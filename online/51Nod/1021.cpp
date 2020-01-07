#include <bits/stdc++.h>
using namespace std;

int n;
int d[1010];
int p[1010][1010];

int get(int front, int back)
{
	return (front < back ? d[back] - d[front-1] : d[n] - d[front-1] + d[back]);
}

int reflect(int x)
{
	return (x-1)%n+1;
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &d[i]), d[i] += d[i-1];

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int k = reflect(j+i-1);
			p[j][k] = p[reflect(j+1)][k] + get(j, k);
			for (int m = j; reflect(m) != k; ++m)
			{
				p[j][k] = min(p[j][k], p[j][reflect(m)]+p[reflect(m+1)][k] + get(j, k));
			}
		}
	}

	printf("%d\n", p[1][n]);
}
