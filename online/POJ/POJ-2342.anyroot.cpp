#include <cstdio>
#include <vector>
#include <cstring> 
using namespace std;

// 以无根树的任一节点作为根，树的性质仍然保留 

const int maxN = 6060;

int val[maxN], bst[maxN];
vector<vector<int> > con;

int mx(int x, int fa)
{
	if (~bst[x]) return bst[x];
	
	int stot = 0, sstot = 0;
	for (unsigned i = 0; i < con[x].size(); ++i)
	{
		if (con[x][i] == fa) continue;
		stot += mx(con[x][i], x);
		for (unsigned j = 0; j < con[con[x][i]].size(); ++j)
		{
			if (con[con[x][i]][j] == x) continue;
			sstot += mx(con[con[x][i]][j], con[x][i]);
		}
	}
	return bst[x] = max(val[x] + sstot, stot);
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	
	int n;
	while (scanf("%d", &n) == 1)
	{
		memset(bst, -1, sizeof(bst));
		con.clear(); con.resize(n+1);
		
		for (int i = 1; i <= n; ++i)
			scanf("%d", &val[i]);
		
		int l, k;
		while (scanf("%d%d", &l, &k) == 2 && l && k)
		{
			con[l].push_back(k);
			con[k].push_back(l);
		}
		
		printf("%d\n", mx(1, -1));
	}
} 

