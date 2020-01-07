// Egg Dropping Puzzles
// https://paine1690.github.io/2017/02/28/algorithm/%E6%89%94%E9%B8%A1%E8%9B%8B%E9%97%AE%E9%A2%98/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxN = 55, maxM = 1010;
const LL INF = 0x3F3F3F3F3F3F3F3F;

LL dp[maxN][maxM];

LL solve(int b, int m)
{
	if (dp[b][m]) return dp[b][m];
	
	if (b == 1) return dp[b][m] = m;
	if (m == 1) return dp[b][m] = 1; 
	if (m == 0) return 0;
	
	dp[b][m] = INF;
	for (int i=1; i<=m; ++i) {
		dp[b][m] = min(dp[b][m], 1+max(solve(b-1, i-1), solve(b, m-i)));
	}
	return dp[b][m];
}

int main()
{
	int P; scanf("%d", &P);
	while (P--)
	{
		memset(dp, 0, sizeof(dp));
		
		int kase, b, m; scanf("%d%d%d", &kase, &b, &m);
		
		solve(b, m);
		printf("%d %lld\n", kase, dp[b][m]);
	}
}
