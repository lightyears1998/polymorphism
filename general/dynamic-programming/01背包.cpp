#include <bits/stdc++.h>
using namespace std;

const int INF  = 0x3F3F3F3F;
const int maxN = 110;
const int maxP = 10010;

int val[maxN], wght[maxN];
int dp[maxP];

int main() 
{
	int n, w; scanf("%d%d", &n, &w);
	for (int i=1; i<=n; ++i) {
		scanf("%d%d", &wght[i], &val[i]);
	}
	
	fill(dp, dp+maxP, -INF); dp[0] = 0;
	for (int i=1; i<=n; ++i) {
		for (int j=w; j>=wght[i]; --j) {
			dp[j] = max(dp[j], dp[j-wght[i]]+val[i]);
		}
	}
	printf("%d\n", *max_element(dp, dp+maxP));
}
