#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int mod  = 1e9+7;
const int maxN = 100010;

int num[maxN];
LL have[maxN], dp[maxN];

int main()
{
	int n; scanf("%d", &n);
	for (int i=1; i<=n; ++i) {
		scanf("%d", &num[i]);
	}
	
	dp[0] = 1;
	for (int i=1; i<=n; ++i) {
		dp[i] = dp[i-1]*2;
		if (have[num[i]] > 0)
			dp[i] -= dp[have[num[i]]-1];
		have[num[i]] = i;
		dp[i] %= mod;
	}
	dp[n] = (dp[n]%mod+mod)%mod;
	
	printf("%lld\n", dp[n]-1);
}
