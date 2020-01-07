#include <cmath>
#include <cstdio>
using namespace std;
typedef long long LL;

LL fpow(LL a, LL b, LL m)
{
	LL ans = 1, base = a % m;
	while (b)
	{
		if (b&1) ans *= base, ans %= m;
		base *= base, base %= m, b >>= 1;
	}
	return ans;
}

int main()
{
	int Z; scanf("%d", &Z);	
	while (Z--)
	{
		int M, H; scanf("%d%d", &M, &H);
		LL ans = 0;
		while (H--)
		{
			LL a, b; scanf("%lld%lld", &a, &b); 
			ans += fpow(a, b, M), ans %= M;
		} 
		printf("%lld\n", ans);
	} 
}

