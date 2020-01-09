#include <bits/stdc++.h>
using namespace std;

const int maxN = 10101010;

bool isprime[maxN];
int prime[maxN];

// 获得 [2, n] 范围内所有素数，tot为素数总数 
// O(n)
void sieve(int n, int& tot)
{
	memset(isprime, true, sizeof(isprime));
	tot = 0; isprime[0] = isprime[1] = false;
	for (int i = 2; i <=n; ++i)
	{
		if (isprime[i]) {
			prime[tot++] = i;
		}
		for (int j = 0; j < tot && (i*prime[j]<=n); ++j)
		{
			isprime[i*prime[j]] = false;
			if (i%prime[j] == 0) break;
		}
	}
}

int main()
{
	int tot; sieve(100010, tot);
	
	int a, b;
	while (cin >> a >> b)
	{
		if (a > b) swap(a, b);
		int c = 0, ans = 0;
		while (c < tot && prime[c] < a) ++c;
		while (c < tot && prime[c] <= b) ++c, ++ans;
		cout << ans << endl;
	}
}

