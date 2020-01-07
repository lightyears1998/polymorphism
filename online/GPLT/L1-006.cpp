#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	
	int bgn = 0, len = 0, range = floor(sqrt(n) + 0.5) + 1;
	for (int i = 2; i <= range; ++i)
	{
		if (n % i == 0) {
			int cur = n;
			for (int j = 1; j <= range; ++j)
			{	
				if (cur % (i+j-1) == 0) {
					cur /= (i+j-1);
					if (j > len) {
						len = j, bgn = i;
					}
				}
				else break;
			}
		}	
	}
	
	if (len == 0) {
		len = 1, bgn = n;
	}
	printf("%d\n", len);
	for (int i = 0; i < len; ++i)
	{
		if (i) putchar('*');
		printf("%d", bgn+i);
	}
	putchar('\n');
}
