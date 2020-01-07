#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int dp[1010][1010];

int main()
{
	int m, n; cin >> n >> m;
	
	dp[0][1] = 1;
	for (int i=1; i<=m; ++i)
		for (int j=1; j<=n; ++j) 
			dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
			
	cout << dp[m][n] << endl;
}
