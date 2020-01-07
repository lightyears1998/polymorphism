#include <bits/stdc++.h>
using namespace std;

const int maxN = 200100;

int arr[maxN];

int leaf[maxN];
struct SegmentTreeNode{
	int l, r;
	long long val, vmx, vmn;
} node[maxN<<2]; 

void init()
{
	memset(leaf, 0, sizeof(leaf));
	memset(node, 0, sizeof(node));
}

void build(int rt, int l, int r, int *arr)
{
	node[rt].l = l, node[rt].r = r;
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

void push(int rt)
{
	while (rt>>=1) {
		node[rt].val = node[rt<<1].val + node[rt<<1|1].val;
		node[rt].vmx = max(node[rt<<1].vmx, node[rt<<1|1].vmx);
		node[rt].vmn = min(node[rt<<1].vmn, node[rt<<1|1].vmn);
	}
}

void modify(int rt, int val) 
{
	node[rt].val = node[rt].vmx = node[rt].vmn = val; 
	push(rt); 
}

void update(int rt, int diff)
{
	node[rt].val += diff;
	node[rt].vmx = node[rt].vmn = node[rt].val; 
	push(rt);
}

long long query(int rt, int l, int r)
{
	if (node[rt].l==l&&node[rt].r==r) 
		return node[rt].val;
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
		return node[rt].vmx;
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
		return node[rt].vmn;
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
	
	int n, m;
	while (scanf("%d%d", &n, &m) == 2)
	{	
		for (int i = 1; i <= n; ++i)
			scanf("%d", &arr[i]);
		init(); build(1, 1, n, arr);
		
		while (m--)
		{
			char cmd[10]; scanf("%s", cmd);
			if (cmd[0] == 'U') {
				int x, d; scanf("%d%d", &x, &d);
				modify(leaf[x], d);
			}
			if (cmd[0] == 'Q') {
				int a, b; scanf("%d%d", &a, &b);
				printf("%lld\n", query_max(1, a, b));
			}
		}
	}
} 

