#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int maxN = 550;
const int maxM = 550;
const int mod  = 1e9+7;

int mod_mult(int a, int b)
{
	int ans = 0, base = a % mod;
	if (b<0) b += mod;
	while (b)
	{
		if (b&1) ans += base; ans %= mod;
		base <<= 1; base %= mod;
		b >>= 1;
	}
	return ans;	
}

struct Matrix
{
	int n, m;
	int v[maxN][maxM];
	
	void clear()
	{
		n = m = 0;
		memset(v, 0, sizeof(v));
	}
	
	Matrix operator + (const Matrix &b) const 
	{
		Matrix ans; ans.n = n, ans.m = m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				ans.v[i][j] = (v[i][j] + b.v[i][j]) % mod;
		return ans;
	}
	
	Matrix operator - (const Matrix &b) const 
	{
		Matrix ans; ans.n = n, ans.m = m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				ans.v[i][j] = (v[i][j] - b.v[i][j]) % mod;
		return ans;
	}
	
	Matrix operator * (const Matrix &b) const
	{
		Matrix ans; ans.clear(); ans.n = n, ans.m = b.m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < b.m; ++j)
			{
				for (int k = 0; k < m; ++k)
				{
					ans.v[i][j] += ((LL)v[i][k] * b.v[k][j]) % mod;
					ans.v[i][j] %= mod;
				}
				if (ans.v[i][j] < 0) ans.v[i][j] += mod;
			}
		return ans;
	}
} a, b, c;

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	
	int n, p, m;
	while (scanf("%d%d%d", &n, &p, &m) == 3)
	{
		a.n = n, a.m = p, b.n = p, b.m = m;
		for (int i = 0; i < n; ++i) 
			for (int j = 0; j < p; ++j)
				scanf("%d", &a.v[i][j]);
		
		for (int i = 0; i < p; ++i)
			for (int j = 0; j < m; ++j)
				scanf("%d", &b.v[i][j]);
		
		c = a*b;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (j) putchar(' ');
				printf("%d", c.v[i][j]);
			}
			putchar('\n');
		}
	}
}
