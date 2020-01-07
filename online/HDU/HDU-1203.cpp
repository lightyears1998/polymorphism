#include <bits/stdc++.h>
using namespace std;

const int maxN = 10010;

int cost[maxN];
double rate[maxN];

double dp[maxN];

int main()
{
	int n, m; 
	
	while (scanf("%d%d", &n, &m) == 2 && (n||m))
	{
		fill(dp, dp+maxN, 1);
		
		for (int i=0; i<m; ++i) {
			scanf("%d %lf", &cost[i], &rate[i]);
			rate[i] = 1-rate[i];
		}
		
		for (int i=0; i<m; ++i) {
			for (int j=n; j-cost[i]>=0; --j) {
				dp[j] = min(dp[j], dp[j-cost[i]]*rate[i]);
			}
		}
		
		#ifdef LOCAL
		for (int i=0; i<=n; ++i) {
			cout << dp[i] << ' ';
		}
		cout << endl;
		#endif
		
		printf("%.1f%%\n", (1-dp[n])*100);
	}
}
