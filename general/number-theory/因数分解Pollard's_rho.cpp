#include <bits/stdc++.h>
using namespace std;
using LL = long long;

// 因数分解Pollard's rho

// Reference:
// https://en.wikipedia.org/wiki/Pollard%27s_rho_algorithm 

int gcd(int x, int y)
{
	return y == 0 ? x : gcd(y, x%y);
}

int factor(int n, int c)
{
	auto g = [&n, &c](int x) {
		return (((LL)x*x)+c) % n;
	};
	
	int x = 2, y = 2, d = 1;
	while (d == 1)
	{
		x = g(x);
		y = g(g(y));
		d = gcd(abs(x-y), n);
	}
	if (d == n) return factor(n, c+1);
	else return d;
}

