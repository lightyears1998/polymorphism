#include <bits/stdc++.h>
using namespace std;

const int INF  = 0x3F3F3F3F;
const int maxN = 1000000;

int n, m;
int w[maxN], p[maxN], c[maxN];

int dn;
int val[maxN], wght[maxN];
int dp[maxN];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; ++i) {
		scanf("%d%d%d", &w[i], &p[i], &c[i]);
	}
	
	for (int i=1; i<=n; ++i) {
		int base = 1;
		while (c[i] > 0) {
			val[++dn] = min(c[i], base) * p[i];
			wght[dn] = min(c[i], base) * w[i];
			c[i] -= base, base *= 2;
		}
	}
	
	fill(dp, dp+maxN, -INF);
	dp[0] = 0;
	for (int i=1; i<=dn; ++i)
	{
		for (int j=m; j>=wght[i]; --j) {
			dp[j] = max(dp[j], dp[j-wght[i]]+val[i]);
		}
	}
	
	printf("%d\n", *max_element(dp, dp+maxN));
}
