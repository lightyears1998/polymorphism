#include <bits/stdc++.h>
using namespace std;

// 性能提示：eps的大小，int()优于floor()

int n, f;
double const pi = acos(-1);
double const eps = 1e-5;
double pie[10010];

int cnt(double size)
{
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		cnt += int(pie[i]/size);
	}
	return cnt;
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &f);

		double l, r; l = r = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%lf", &pie[i]);
			pie[i] *= pie[i];
			r = max(r, pie[i]);
		}

		while (r - l > eps)
		{
			double mid = (l+r)/2;
			if (cnt(mid) >= f+1)
		 		l = mid;
		 	else r = mid;
		}
		printf("%.4lf\n", pi*r);
	}
}
