#include <cstdio>
#include <vector>
#include <cstring> 
using namespace std;

const int maxN = 6060;

int val[maxN], bst[maxN];
int father[maxN];
vector<vector<int> > son;

int find(int x)
{
	while (father[x]) x = father[x];
	return x;
}

int mx(int x)
{
	if (~bst[x]) return bst[x];
	
	int stot = 0, sstot = 0;
	for (unsigned i = 0; i < son[x].size(); ++i)
	{
		stot += mx(son[x][i]);
		for (unsigned j = 0; j < son[son[x][i]].size(); ++j)
		{
			sstot += mx(son[son[x][i]][j]);
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
		memset(father, 0, sizeof(father));
		memset(bst, -1, sizeof(bst));
		son.clear(); son.resize(n+1);
		
		for (int i = 1; i <= n; ++i)
			scanf("%d", &val[i]);
		
		int l, k;
		while (scanf("%d%d", &l, &k) == 2 && l && k)
		{
			father[l] = k;
			son[k].push_back(l);
		}
		
		int root = find(1);
		printf("%d\n", mx(root));
	}
} 

