#include <bits/stdc++.h>
using namespace std;

// Reference: 
// https://blog.csdn.net/HowardEmily/article/details/66974553
// https://www.liuchuo.net/archives/2327

const int maxN = 10100;
const int INF  = 0x3F3F3F3F;

int n, m;
int coin[maxN];
int dp[maxN], choice[maxN], pre[maxN];

void print(int u)
{
	if (!pre[u]) {
		printf("%d", choice[u]);
		return;
	}
	print(pre[u]);
	printf(" %d", choice[u]);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; ++i)
		scanf("%d", &coin[i]);
		
	sort(coin+1, coin+1+n);
	fill(dp, dp+maxN, -INF);
	dp[0] = 0;
	
	for (int i=1; i<=n; ++i)
		for (int j=m; j>=coin[i]; --j)
		{
			if (dp[j] <= dp[j-coin[i]] + 1) {
				dp[j] = dp[j-coin[i]] + 1;
				pre[j] = j-coin[i];
				choice[j] = coin[i];
			}
		}
	
	if (dp[m] > 0) {
		print(m);
	}
	else printf("No Solution\n");
}

