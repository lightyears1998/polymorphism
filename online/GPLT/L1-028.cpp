#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; scanf("%d", &n);
	
	while (n--)
	{
		int i; scanf("%d", &i);
		
		if (i < 2) {
			printf("No\n");
			continue; 
		}
		if (i == 2) {
			printf("Yes\n");
			continue;
		}
		
		int range = floor(sqrt(i) + 0.5);
		bool ok = true;
		for (int j = 2; ok && j <= range; ++j)
			if (i % j == 0) ok = false;
		printf((ok ? "Yes\n" : "No\n"));
	}
} 
