#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL gcd(LL a, LL b, LL &x, LL &y)
{
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	else {
		LL r = gcd(b, a%b, y, x);
		y -= (a/b)*x;
		return r;
	}
}

vector<LL> line_mod_equation(LL a, LL b, LL n)
{
	LL x, y;
	LL d = gcd(a, n, x, y);
	
	vector<LL> ans;
	if (b%d == 0) {
		x %= n; x += n; x %= n;
		ans.push_back(x*(b/d)%(n/d));
		for (LL i=1; i<d; ++i)	
			ans.push_back((ans[0]+i*(n/d))%n);
	}
	return ans;
}

int main()
{
	LL a, b, n;
	while (cin >> a >> b >> n)
	{
		for (LL i : line_mod_equation(a, b, n)) {
			cout << i << ' ';
			cout << a << '*' << i << '%' << n << '=' << a*i%n << endl;
		}
	}
}
