#include <bits/stdc++.h>
using namespace std;

// rk[x] = r(x->find(x)): 0-同类 1-捕食者 2-被捕食者

int n;
int fa[50500], rk[50500];

void init()
{
	for (int i = 0; i <= n; ++i) fa[i] = i, rk[i] = 0;
}

int find(int x)
{
	if (fa[x] == x) return x;
	int old = fa[x]; fa[x] = find(fa[x]);
	rk[x] = (rk[x] + rk[old]) % 3;
	return fa[x];
}

bool check(int a, int b, int r)
{
	if (max(a, b) > n) return false;
	if (a==b && r!=0) return false;
	if (find(a) != find(b)) return true;
	return rk[a] == (r+rk[b])%3;
}

void merge(int a, int b, int r)
{
	int ra = find(a), rb = find(b);
	if (ra == rb) return;
	fa[ra] = rb; rk[ra] = (r+rk[b]-rk[a]+3)%3;
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif

	int k; scanf("%d%d", &n, &k);
	{
		init(); int ans = 0;
		while (k--)
		{
			int r, x, y; scanf("%d%d%d", &r, &x, &y);
			if (!check(x, y, r-1)) ++ans;
			else merge(x, y, r-1);
		}
		printf("%d\n", ans);
	}
}
