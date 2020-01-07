#include <cmath>
#include <cstdio>
using namespace std;

LL gcd(LL a, LL b)
{
	return b == 0 ? a : gcd(b, a % b);
}

LL lcm(LL a, LL b)
{
	return a * b / gcd(a, b);
}

int main()
{
	LL agcd, alcm;
	while (scanf("%lld%lld", &agcd, &alcm) == 2)
	{
		LL product = alcm / agcd;
		LL high = product^1 + product&1;
		LL low  = product^1;
		
	}
}

