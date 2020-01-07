#include <cstdio>
#include <cmath>
using namespace std;
typedef long long LL;

bool isprime(LL n)
{
	if (n <= 1) return false;
	if (n == 2) return true;
	bool ok = true;
	LL range = floor(sqrt(n) + 0.5);
	for (LL i = 2; ok && i <= range; ++i)
	{
		if (n % i == 0) ok = false;
	}
	return ok;
}

LL fpow(LL a, LL p)
{
	LL ans = 1, mod = p, base = a % p;
	while (p)
	{
		if (p&1) {
			ans *= base, ans %= mod;
		}
		base *= base, base %= mod;
		p >>= 1;
	}
	return ans;
}

int main()
{
	LL a, p;
	while (scanf("%lld%lld", &p, &a) == 2 && a && p)
	{
		puts(!isprime(p) && (fpow(a, p) == a) ? "yes" : "no");
	}
} 

