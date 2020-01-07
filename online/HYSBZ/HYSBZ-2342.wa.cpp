#include <bits/stdc++.h>
using namespace std;

char str[5005000];

int main()
{	
	int n; str[0] = '#';
	while (scanf("%d%s", &n, str+1) == 2)
	{
		int i = 1, mx = 0;
		while (str[i])
		{
			int l(i), r(i);
			while (str[r] == str[r+1]) ++r;
			int cur = r - l + 1;
			while (str[l-1] == str[r+1]) {
				--l, ++r, cur += 2;
			}
			
			if (cur % 4 == 0) {
				int len = cur / 2;
				
				int ll = l, rr = l+len-1;
				while (str[ll] == str[rr] && ll <= rr) ++ll, --rr;
				if (ll > rr) mx = max(mx, cur);
			}
			++i;
		}
		printf("%d\n", mx);
	}
}
