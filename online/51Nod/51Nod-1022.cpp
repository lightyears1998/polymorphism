#include <bits/stdc++.h>
using namespace std;

// 四边形不等式DP优化
// https://hrbust-acm-team.gitbooks.io/acm-book/content/dynamic_programming/opt.html

int n;
int d[1010];
int p[1010][1010];
int s[1010][1010];

int get(int front, int back)
{
	return (front < back ? d[back] - d[front-1] : d[n] - d[front-1] + d[back]);
}

int reflect(int x)
{
	return (x-1+n)%n+1;
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &d[i]), d[i] += d[i-1], s[i][i] = i;

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int k = reflect(j+i-1);
			p[j][k] = p[reflect(j+1)][k];
			s[j][k] = j;
			for (int m = s[j][reflect(k-1)]; reflect(m) != reflect(s[reflect(j+1)][k]+1); ++m)
			{
				if (p[j][k] > p[j][reflect(m)]+p[reflect(m+1)][k]) {
					p[j][k] = p[j][reflect(m)]+p[reflect(m+1)][k];
					s[j][k] = reflect(m);
				}
			}
			p[j][k] += get(j, k);
		}
	}

	int ans = p[1][n];
	for (int i = 2; i <= n; ++i)
		ans = min(ans, p[i][reflect(i+n-1)]);

	printf("%d\n", ans);
}
