#include <bits/stdc++.h>
using namespace std;

int crystall[10100];

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif 
	
	int t; scanf("%d", &t);
	while (t--)
	{
		int n, k; scanf("%d%d", &n, &k);
	
		int up = 0, down = 0;
		for (int i = 0; i < n; ++i)
			scanf("%d", &crystall[i]);
		for (int i = 0; i < n; ++i)
		{
			char c; scanf(" %c", &c);
			if (c == 'L') up += crystall[i];
			if (c == 'D') down -= crystall[i];
			if (c == 'N') 
				up += crystall[i], down -= crystall[i];
		}
		
		if (k >= down && k <= up)
			printf("yes\n");
		else 
			printf("no\n");	
	}
}

