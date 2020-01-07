#include <bits/stdc++.h>
using namespace std;

int tme[1010];
int dp[110][110];

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	int kase; cin >> kase;
	while (kase--)
	{
		memset(dp, 0, sizeof(dp));
		memset(tme, 0, sizeof(tme));
		int n, t, m; cin >> n >> t >> m;
		
		for (int i = 1; i <= n; ++i)
			scanf((i==1 ? "%d" : ", %d"), &tme[i]);
		
		for (int i = 1; i <= n; ++i)
		{
			for (int j = m; j; --j)
			{
				for (int k = t; k >= tme[i]; --k)
				{
					dp[j][k] = max(dp[j][k], dp[j-1][t] + 1);
					dp[j][k] = max(dp[j][k], dp[j][k - tme[i]] + 1);
				}
			}
		}
		
		cout << dp[m][t] << endl;
		if (kase) cout << endl;
	}
} 

