// Unablet to finishe due to lack of experience,
// But I mamage to understand it now.

#include <bits/stdc++.h>
using namespace std;

int cnt[20020];

int main()
{
	// freopen("in.txt", "r", stdin);
		
	int t; scanf("%d", &t);
	while (t--)
	{
		memset(cnt, 0, sizeof(cnt));
		
		int n; scanf("%d", &n);
		int maxn = 0;
		
		for (int i = 0; i < n; ++i)
		{
			int s; scanf("%d", &s);
			cnt[s] = cnt[s - 1] + 1;
			maxn = max(maxn, s);
		}
		
		int ans = 0;
		for(int i = 1; i <= maxn; ++i)
			ans = max(ans, cnt[i]);
		printf("%d\n", ans);
	}
}
