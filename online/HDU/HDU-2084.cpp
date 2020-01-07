#include <bits/stdc++.h>
using namespace std;

int tower[110][110]; 

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	
	int c; scanf("%d", &c);
	while (c--)
	{
		memset(tower, 0, sizeof(tower));
		
		int n; scanf("%d", &n); 
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= i; ++j)
			{
				scanf("%d", &tower[i][j]);
				tower[i][j] += max(tower[i - 1][j], tower[i - 1][j - 1]);	
			}
		}
		
		printf("%d\n", *max_element(tower[n] + 1, tower[n] + n + 1));
	}
}

