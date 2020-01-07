#include <cstdio>

int main()
{
	double d;
	while (scanf("%lf", &d) == 1 && d != 0)
	{
		double tot = 0; int need;
		for (need = 1; tot < d; ++need)
		{
			tot += 1 / double(need + 1);
		}
		printf("%d card(s)\n", need-1);
	}
}

