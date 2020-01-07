#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL split(LL n, LL m)
{
	if (n == 1 || m == 1) return 1;
	if (n < m) return split(n, n);
	if (n == m) return 1 + split(n, m - 1); 
	return split(n - m, m) + split(n, m - 1); 
}

LL split(LL n)
{
	return split(n, n);
}

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		printf("%d\n", split(n));
	} 
}
