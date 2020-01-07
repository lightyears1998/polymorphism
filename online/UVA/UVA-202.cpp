#include <cstdio>

int bgn, end;
int quotient[1000100];
int remainer[1000100];

bool check(int i)
{
	if (quotient[i] == 0 && remainer[i] == 0) {
		bgn = i, end = i;
		return true;
	}
	for (int j = i - 1; j > 0; --j)
	{
		if (quotient[j] == quotient[i] && remainer[j] == remainer[i]) {
			bgn = j, end = i - 1;
			return true;
		}
	}
	return false;
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	int numerator, denominator;
	while (scanf("%d%d", &numerator, &denominator) == 2)
	{	
		printf("%d/%d = ", numerator, denominator);
		
		int i;
		for (i = 0; true; ++i)
		{
			quotient[i] = numerator / denominator;
			remainer[i] = numerator % denominator;
			numerator = remainer[i], numerator *= 10;
			if (i && check(i)) break;
		}
		
		for (int j = 0; j <= i; ++j)
		{
			if (j == bgn) printf("(");
			
			printf("%d", quotient[j]);
			if (j == 0) printf(".");
			if (j == end) {
				printf(")\n");
				break;	
			}
			if (j == 50) {
				printf("...)\n");
				break;
			}
		}
		printf("   %d = number of digits in repeating cycle\n", end - bgn + 1);
		printf("\n");
	}
}

