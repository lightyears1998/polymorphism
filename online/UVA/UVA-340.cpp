#include <bits/stdc++.h>
using namespace std;

int secret[1010], guess[1010];
int scnt[10], gcnt[10];

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	
	int n, kase = 0; 
	while (scanf("%d", &n) == 1 && n)
	{
		printf("Game %d:\n", ++kase);
		memset(scnt, 0, sizeof(scnt));		
		for (int i = 0; i < n; ++i) 
		{
			scanf("%d", &secret[i]);
			++scnt[secret[i]];
		}
		
		while (true)
		{
			memset(gcnt, 0, sizeof(gcnt));
			for (int i = 0; i < n; ++i)
			{
				scanf("%d", &guess[i]);
				++gcnt[guess[i]];
			}
			if (gcnt[0] == n) break;
			
			int ans1 = 0, ans2 = 0;
			for (int i = 0; i < n; ++i)
				if (secret[i] == guess[i]) ++ans1;
			for (int i = 1; i <= 9; ++i)
				ans2 += min(scnt[i], gcnt[i]);
			ans2 -= ans1;
			printf("    (%d,%d)\n", ans1, ans2);
		}
	}
}
