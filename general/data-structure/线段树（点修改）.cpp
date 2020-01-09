// 初始化，建树，修改和查询
// 利用leaf数组可快速找到叶子节点


// 线段树的空间问题
// 一般情况下，空间开4倍即可
// 如果pushup()方法中，上层节点主动收取下层节点的值，则需要8倍空间，以避免下层节点越界
// 参见 http://codeforces.com/contest/610/submission/35762143

const int maxN = 200100;

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

void pushup(int rt)
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
	pushup(rt); 
}

void update(int rt, int diff)
{
	node[rt].val += diff;
	node[rt].vmx = node[rt].vmn = node[rt].val; 
	pushup(rt);
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
