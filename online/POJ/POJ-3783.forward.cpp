// Egg Dropping Puzzles
// https://paine1690.github.io/2017/02/28/algorithm/%E6%89%94%E9%B8%A1%E8%9B%8B%E9%97%AE%E9%A2%98/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxN = 55, maxM = 1010;

LL dp[maxN][maxM];

void cal()
{
	memset(dp, 0x3F, sizeof(dp));
	
	for (int i=1; i<maxN; ++i) 
		dp[i][0] = 0, dp[i][1] = 1  ;
	for (int j=0; j<maxM; ++j)
		dp[1][j] = j;
	
	for (int i=2; i<maxN; ++i) {
		dp[i][1] = 1;
		for (int j=2; j<maxM; ++j) {
			for (int k=1; k<j; ++k) {
				dp[i][j] = min(dp[i][j], 1+max(dp[i][j-k], dp[i-1][k-1]));
			}
		}
	}
}

int main()
{
	cal();
	
	int P; scanf("%d", &P);
	while (P--)
	{
		int kase, b, m; scanf("%d%d%d", &kase, &b, &m);
		printf("%d %lld\n", kase, dp[b][m]);
	}
}
