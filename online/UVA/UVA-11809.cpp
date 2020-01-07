#include <bits/stdc++.h>
using namespace std;

char buf[40];

double LogA[10][32], B[10][32];

void init()
{
	for (int e=1; e<=30; ++e)
	{
		for (int m=0; m<=9; ++m)
		{
			double rslt = log10(1-pow(0.5, m+1))+((1LL<<e)-1)*log10(2);
			LogA[m][e] = modf(rslt, &B[m][e]);
		}
	}
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	init();	
	while (scanf("%s", buf) == 1)
	{
		if (!strcmp(buf, "0e0")) break;
		
		double a, b;
		sscanf(buf, "%17lfe%lf", &a, &b);
		a = log10(a);
		
		int ce=1, cm=1; double eps = abs(a-LogA[1][1]+b-B[1][1]);
		for (int e=1; e<=30; ++e)
		{
			for (int m=0; m<=9; ++m)
			{
				double kan = abs(a-LogA[m][e]+b-B[m][e]);
				if (kan < eps) {
					ce=e, cm=m, eps = kan;
				}
			}	
		}
		printf("%d %d\n", cm, ce);
	}
}

