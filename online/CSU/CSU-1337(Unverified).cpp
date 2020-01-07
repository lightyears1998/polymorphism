#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long x, y, kase = 0;
	while (scanf("%lld%lld", &x, &y) == 2)
	{
		int cnt = 0;
		for (long long i = x; i <= 1000 && i <= y; ++i)
		{
			for (long long j = x; j <= 1000 && j <= y; ++j)
			{
				long long rslt = i * i * i + j * j * j;
				if (rslt % 10 == 3 && (rslt / 10) <= y)
					++cnt;
			}
		}
		printf("Case %lld: %d\n", ++kase, cnt);
	}
}

