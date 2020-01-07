#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxN = 50050;

int n;
int num[maxN];
int mx[maxN][18], mn[maxN][18];

void init()
{
	int bound = ceil(log2(n));
	for (int i = 0; i < n; ++i)
		mx[i][0] = mn[i][0] = num[i];
		
	for (int i = 1; i <= bound; ++i)
		for (int j = 0; j < n; ++j)
		{
			mx[j][i] = max(mx[j][i-1], mx[min(j+(1<<(i-1)), n)][i-1]);
			mn[j][i] = min(mn[j][i-1], mn[min(j+(1<<(i-1)), n)][i-1]);
		}
}

int query(int a, int b)
{
	int k = floor(log2(b-a+1));
	return max(mx[a][k], mx[b-(1<<k)+1][k]) - min(mn[a][k], mn[b-(1<<k)+1][k]);
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	
	int q;
	while (scanf("%d%d", &n, &q) == 2)
	{
		for (int i = 0; i < n; ++i) 
			scanf("%d", &num[i]);

		init();
		while (q--)
		{
			int a, b; scanf("%d%d", &a, &b);
			printf("%d\n", query(a-1, b-1));
		}
	}
}
