#include <bits/stdc++.h>
using namespace std;
using LL = long long;

template<typename T = int>
inline void read(T& val) {
	val = 0; T sign = 1; char ch;
	for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
		if (ch == '-') sign = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar())
		val = val * 10 + ch - '0';
	val *= sign;
}

int fa[4000004], w[4000004];

void init(int n)
{
	for (int i = 0; i < n; ++i)	fa[i] = i;
}

int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

bool query(int a, int b)
{
	return find(a) == find(b);
}

void merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a == b) return;
	if (w[a] > w[b]) swap(a, b);
	fa[a] = b, ++w[b];
} 

int main()
{
	int n, m; read(n), read(m);
	init(n); LL ans = 0;
	
	while (m--)
	{
		int op, u, v; read(op); read(u); read(v);
		switch (op) {
			case 0: {
				merge(u, v);
				break;
			}
			case 1: {
				ans <<= 1;
				if (query(u, v)) ans += 1;
				ans %= 998244353;
				break;
			}
		}
	}
	printf("%lld\n", ans);
}
