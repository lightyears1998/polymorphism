#include <bits/stdc++.h>
using namespace std;

const int maxN = 16001;
bool isprime[maxN];
int prime[maxN];

void sieve(int n, int& tot)
{
	memset(isprime, true, sizeof(isprime));
	tot = 0; isprime[0] = isprime[1] = false;
	for (int i = 2; i <= n; ++i)
	{
		if (isprime[i]) {
			prime[tot++] = i;
		}
		for (int j = 0; j<tot && i*prime[j]<=n; ++j)
		{
			isprime[i*prime[j]] = false;
			if (i%prime[j]==0) break;
		}
	}
	isprime[2] = false;
}

int main()
{
	int tot; sieve(16000, tot);
	
	int n, kase = 0; 
	while (scanf("%d", &n) == 1 && n>0)
	{
		printf("%d: %s\n", ++kase, (isprime[n] ? "yes" : "no"));
	}
}

