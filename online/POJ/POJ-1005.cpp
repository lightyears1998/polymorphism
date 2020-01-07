#include <cstdio>
#include <cmath>

const double PI = acos(-1);

int main()
{
	int n; scanf("%d", &n);
	for (int kase = 1; kase <= n; ++kase)
	{
		double x, y; scanf("%lf%lf", &x, &y);
		double dis = sqrt(x * x + y * y);
		for (int i = 1; i; ++i)
		{
			double r = sqrt(100*i / PI);
			if (r > dis) {
				printf("Property %d: This property will begin eroding in year %d.\n", kase, i);
				break;
			}
		}
	}
	printf("END OF OUTPUT.");
}

