#include <bits/stdc++.h>
using namespace std;
using LL = long long;

// http://www.cielyang.com/poj1061-%E9%9D%92%E8%9B%99%E7%9A%84%E7%BA%A6%E4%BC%9A/

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

LL solve(LL a, LL b, LL n)
{
	a%=n, a+=n, a%=n; 
	b%=n, b+=n, b%=n;
		
	LL x, y;
	LL d = gcd(a, n, x, y);
	if (b%d==0) {
		x%=n; x+=n; x%=n;
		return x*(b/d)%(n/d);
	}
	else return -1;
}

int main()
{
	LL x, y, n, m, L;
	while (scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &L) == 5) {
		LL ans = solve(m-n, y-x, L);
		if (~ans) {
			printf("%lld\n", ans);
		}
		else printf("Impossible\n"); 
	}
} 
