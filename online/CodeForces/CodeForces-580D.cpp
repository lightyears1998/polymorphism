#include <bits/stdc++.h>
using namespace std;

int n, m, k;
long long best;
long long dish[20];
long long comb[20][20];
long long dp[1<<20][20]; // dp[st][i] 表示st状态下以j-th道菜结尾的最佳得分

int popcount(long long x)
{
	int cnt = 0;
	while (x)
	{
		if (x&1) ++cnt;
		x >>= 1;
	}
	return cnt;
}

void solve()
{
	for (long long st = 1; st < (1<<n); ++st)
	{
		int cnt = popcount(st);
		if (cnt > m) continue;

		bool single = true;
		for (long long i = 0; (1<<i) <= st; ++i) if ((1<<i)&st)
		{
			for (long long j = 0; (1<<j) <= st; ++j) if (i!=j && (1<<j)&st)
			{
				single = false;
				dp[st][i] = max(dp[st][i], dp[st^(1<<i)][j] + dish[i] + comb[j][i]);
			}
			if (single) {
				dp[st][i] = dish[i];
			}
			if (cnt == m)
				best = max(best, dp[st][i]);
		}
	}
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif

	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
	{
		int j; cin >> j;
		dish[i] = j;
	}
	while (k--)
	{
		int x, y, c; cin >> x >> y >> c;
		comb[x-1][y-1] = c;
	}

	solve();
	cout << best << endl;
}
