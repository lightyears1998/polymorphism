// 树状数组，适用于单点修改，区间和查询
#include <bits/stdc++.h>

struct FenwickTree
{
	const static int MXN = 50050;
	int tree[MXN];
	
	void clear()
	{
		memset(tree, 0, sizeof(tree));
	}
	
	int lowbit(int x)
	{
		return x & -x; 
	}
	
	void add(int x, int v)
	{
		for (int i = x; i < MXN; i += lowbit(i))
			tree[i] += v;
	} 
	
	int get(int x)
	{
		int sum = 0;
		for (int i = x; i; i -= lowbit(i))
			sum += tree[i];
		return sum;
	}
} tree;

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	
	int t, kase = 0; scanf("%d", &t);
	while (t--)
	{
		tree.clear();
		printf("Case %d:\n", ++kase);
		
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
		{
			int v; scanf("%d", &v);
			tree.add(i, v);
		}
		
		char cmd[10];
		while (scanf("%s", cmd) == 1)
		{
			if (cmd[0] == 'Q')
			{
				int a, b; scanf("%d%d", &a, &b);
				printf("%d\n", tree.get(b) - tree.get(a - 1));
			}
			if (cmd[0] == 'A')
			{
				int x, v; scanf("%d%d", &x, &v);
				tree.add(x, v);
			}
			if (cmd[0] == 'S')
			{
				int x, v; scanf("%d%d", &x, &v);
				tree.add(x, -v);
			}
			if (cmd[0] == 'E') break;
		}
	}
}
