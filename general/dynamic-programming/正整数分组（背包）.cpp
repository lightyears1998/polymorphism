#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3F3F3F3F;

int num[110];
int dp[10001];

int main()
{
	int n; scanf("%d", &n);
	for (int i=1; i<=n; ++i) {
		scanf("%d", &num[i]);
	}
	
	int sum = accumulate(num, num+n+1, 0);
	int halfsum = sum/2;
	
	fill(dp, dp+10001, -INF);
	dp[0] = 0;
	for (int i=1; i<=n; ++i) {
		for (int j=halfsum; j>=num[i]; --j) {
			dp[j] = max(dp[j], dp[j-num[i]]+num[i]);
		}
	}
	
	int mx = *max_element(dp, dp+10001);
	printf("%d\n", (sum-mx-mx));
} 
