#include <cstdio>

bool ok(int fst, int cur, int seg)
{
	return !((fst-cur)%seg);
}

int main()
{
	int t = 0;
	int p, e, i, d; while (scanf("%d%d%d%d", &p, &e, &i, &d) == 4 && ~p)
	{
		for (int j = 1; j <= 21252; ++j)
		{
			if (ok(p, d+j, 23) && ok(e, d+j, 28) && ok(i, d+j, 33))
			{
				printf("Case %d: the next triple peak occurs in %d days.\n", ++t, j);
				break;
			}
		}
	}
}

