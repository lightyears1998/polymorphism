#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int maxN = 100100;

LL bit[maxN], deltax[maxN];

int lowbit(int x) {
	return x & (-x);
}

void add(LL* gp, int x, LL v)
{
	while (x < maxN)
	{
		gp[x] += v;
		x += lowbit(x);
	}
}

LL sum(LL* gp, int x)
{
	LL ans = 0;
	while (x)
	{
		ans += gp[x];
		x -= lowbit(x);
	}
	return ans;
}

LL sum(LL* gp, int a, int b) { 
	return sum(gp, b) - sum(gp, a-1);
}

void update(int a, int b, LL v)
{
	add(bit, a, v);
	add(bit, b+1, -v);
	add(deltax, a, a*v);
	add(deltax, b+1, -(b+1)*v);
}

LL sum(int x) {
	return sum(bit, x) * (x+1) - sum(deltax, x);
}

LL query(int a, int b)
{
	return sum(b) - sum(a-1);
}

int main()
{
	int n, q; while (scanf("%d%d", &n, &q) == 2)
	{
		memset(bit, 0, sizeof(bit));
		memset(deltax, 0, sizeof(deltax));
		
		for (int i = 1; i <= n; ++i)
		{
			LL v; scanf("%lld", &v);
			update(i, i, v);
		}
		while (q--)
		{
			char buf[10]; scanf("%s", buf);
			if (buf[0] == 'C') {
				int a, b; LL c; scanf("%d%d%lld", &a, &b, &c);
				update(a, b, c);
			} 
			if (buf[0] == 'Q') {
				int a, b; scanf("%d%d", &a, &b);
				printf("%lld\n", query(a, b));
			}
		}
	}
}
