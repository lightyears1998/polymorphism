#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL gcd(LL a, LL b)
{
	return (b == 0) ? a : gcd(b, a % b);
}

LL lcm(LL a, LL b)
{
	return a * b / gcd(a, b);
}

int main()
{
	LL a, b;
	while (scanf("%lld%lld", &a, &b) == 2)
	{
		printf("%lld %lld\n", gcd(a, b), lcm(a, b));
	}
}

