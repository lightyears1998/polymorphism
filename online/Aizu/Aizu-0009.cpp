#include <bits/stdc++.h>
using namespace std;

const int maxN = 1123456;

int prime[maxN];
bool isprime[maxN];

void sieve(int n, int& tot)
{
	memset(isprime, true, sizeof(isprime));
	tot = 0; isprime[0] = isprime[1] = false;
	for (int i = 2; i < n; ++i) 
	{
		if (isprime[i]) {
			prime[tot++] = i;
		}
		for (int j = 0; j < tot && i*prime[j] <= n; ++j)
		{
			isprime[i*prime[j]] = false;
			if (i%prime[j]==0) break;
		}
	}
}

int main()
{
	int tot; sieve(1000100, tot);
	int n;
	while (scanf("%d", &n) == 1)
	{
		int tot = 0; 
		for (int i = 0; prime[i]<=n; ++i) ++tot;
		printf("%d\n", tot);
	}
}

