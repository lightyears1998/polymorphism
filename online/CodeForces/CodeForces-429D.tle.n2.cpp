#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL dot[100100];
LL sum[100100];

template<typename T = int>
inline void read(T& val) {
	val = 0; T sign = 1; char ch;
	for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
		if (ch == '-') sign = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar())
		val = val * 10 + ch - '0';
	val *= sign;
}

auto sqr = [](LL n)
{
	return n * n;
};

auto g = [](int i, int j)
{
	return sqr(sum[j] - sum[i]); 
};

int main()
{
	int n; read(n);
	for (int i = 1; i <= n; ++i)
	{
		read(dot[i]);
		sum[i] = sum[i-1] + dot[i];
	}
	
	LL candidate = 1 + g(1, 2); 
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i+1; j <= n; ++j)
		{
			LL cur = sqr(i-j);
			if (cur >= candidate) break;
			cur += g(i, j);
			candidate = min(candidate, cur);
		}
	}
	printf("%lld\n", candidate);
}
