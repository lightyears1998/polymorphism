#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL a, b, c, d;

LL gcd(LL a, LL b)
{
	return b == 0 ? a : gcd(b, a%b);
}

LL lcm(LL a, LL b)
{
	return a * b / gcd(a, b);
}

void simplify(LL &a, LL &b)
{
	LL g = gcd(abs(a), abs(b));
	a /= g, b /= g;
}

void add()
{
	LL m = lcm(b, d);
	a *= m/b, c *= m/d;
	a += c, b = m;
}

void show()
{
	if (abs(a) >= b) {
		LL t = a/b;
		printf("%lld", t);
		a -= t*b;
		if (a) printf(" %lld/%lld", a, b);
	}
	else if(a) printf("%lld/%lld", a, b);
	else printf("0");
	putchar('\n');
}

signed main()
{
	int n; scanf("%d", &n);
	
	scanf("%lld/%lld", &a, &b); simplify(a, b);
	while (--n)
	{
		scanf("%lld/%lld", &c, &d); simplify(c, d);
		add();
		simplify(a, b);
	}
	
	show();
}
