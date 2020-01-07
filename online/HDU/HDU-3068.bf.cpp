#include <bits/stdc++.h>
using namespace std;

char str[110110];

int main()
{
	while (scanf("%s", str+1) == 1)
	{
		int i = 0, mx = 1;
		str[0] = '*'; // 回避下标越界问题，减少判定越界的时间

		while (str[i])
		{
			int q = i, p = i;

			while (str[i+1] == str[i]) ++i;
			p = i;

			while (str[q-1] == str[p+1]) --q, ++p;
			mx = max(mx, p - q + 1);

			++i; // i = p + 1;
			// 回文串能拓展到p处，但p之前可能有更强的回文中心

		}
		printf("%d\n", mx);
	}
}
