#include <bits/stdc++.h>
using namespace std;

const int maxN = 200100;

int arr[maxN];

int leaf[maxN];
struct SegmentTreeNode{
	int l, r;
	long long val, vmx, vmn;
	long long lazy;
} node[maxN<<2]; 

void init()
{
	memset(leaf, 0, sizeof(leaf));
	memset(node, 0, sizeof(node));
}

void build(int rt, int l, int r, int *arr)
{
	node[rt].l = l, node[rt].r = r;
	node[rt].lazy = 0;
	if (l==r)
	{
		leaf[l] = rt;
		node[rt].val = node[rt].vmx = node[rt].vmn = arr[l];
	}
	else
	{
		int mid = (l+r)/2;
		build(rt<<1, l, mid, arr);
		build(rt<<1|1, mid+1, r, arr);
		node[rt].val = node[rt<<1].val + node[rt<<1|1].val;
		node[rt].vmx = max(node[rt<<1].vmx, node[rt<<1|1].vmx);
		node[rt].vmn = min(node[rt<<1].vmn, node[rt<<1|1].vmn);
	}
}

void pushup(int rt)
{
	while (rt>>=1) {
		node[rt].val = node[rt<<1].val + node[rt<<1|1].val;
		node[rt].vmx = max(node[rt<<1].vmx, node[rt<<1|1].vmx);
		node[rt].vmn = min(node[rt<<1].vmn, node[rt<<1|1].vmn);
	}
}
 
void pushdown(int rt)
{
	if (node[rt].lazy) {
		node[rt].val += node[rt].lazy*(node[rt].r-node[rt].l+1);
		node[rt].vmx += node[rt].lazy;
		node[rt].vmn += node[rt].lazy;
		node[rt<<1].lazy += node[rt].lazy;
		node[rt<<1|1].lazy += node[rt].lazy;
	}
	node[rt].lazy = 0;
}

void modify(int rt, int val) 
{
	node[rt].val = node[rt].vmx = node[rt].vmn = val; 
	pushup(rt); 
}

void update(int rt, int diff)
{
	node[rt].val += diff;
	node[rt].vmx = node[rt].vmn = node[rt].val; 
	pushup(rt);
}

void update(int rt, int l, int r, int diff)
{
	if (l<=node[rt].l&&node[rt].r<=r) {
		node[rt].lazy += diff;
		return;
	}
	int mid = (node[rt].l+node[rt].r)/2;
	if (r<=mid) {
		update(rt<<1, l, r, diff);
	} 
	else if (mid<l) {
		update(rt<<1|1, l, r, diff);
	}
	else {
		update(rt<<1, l, r, diff);
		update(rt<<1|1, l, r, diff);
	}
}

long long query(int rt, int l, int r)
{
	if (node[rt].l==l&&node[rt].r==r)
		return node[rt].val + node[rt].lazy;
	pushdown(rt);
	int mid = (node[rt].l+node[rt].r)/2;
	if (r<=mid)
		return query(rt<<1, l, r);
	else if(mid<l)
		return query(rt<<1|1, l, r);
	else
		return query(rt<<1, l, mid) + query(rt<<1|1, mid+1, r);
}

long long query_max(int rt, int l, int r)
{
	if (node[rt].l==l&&node[rt].r==r) 
		return node[rt].vmx + node[rt].lazy;
	pushdown(rt);
	int mid = (node[rt].l+node[rt].r)/2;
	if (r<=mid)
		return query_max(rt<<1, l, r);
	else if(mid<l)
		return query_max(rt<<1|1, l, r);
	else
		return max(query_max(rt<<1, l, mid), query_max(rt<<1|1, mid+1, r));
}

long long query_min(int rt, int l, int r)
{
	if (node[rt].l==l&&node[rt].r==r)
		return node[rt].vmn + node[rt].lazy;
	pushdown(rt);
	int mid = (node[rt].l+node[rt].r)/2;
	if (r<=mid)
		return query_min(rt<<1, l, r);
	else if(mid<l)
		return query_min(rt<<1|1, l, r);
	else
		return min(query_min(rt<<1, l, mid), query_min(rt<<1|1, mid+1, r));
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	
	int n;
	while (scanf("%d", &n) == 1 && n)
	{
		for (int i = 1; i <= n; ++i)
			arr[i] = 0;
		build(1, 1, n, arr);
		for (int i = 1; i <= n; ++i)
		{
			int a, b; scanf("%d%d", &a, &b);
			update(1, a, b, 1);
		}
		
		for (int i = 1; i <= n; ++i)
		{
			printf("%lld", query(1, i, i));
			putchar(i != n ? ' ' : '\n'); 
		}
	}
}

