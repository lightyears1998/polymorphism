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

int main()
{
	int n = (int)3e6; LL pot = 0;
	while (n--)
	{
		LL i; read(i);
		pot ^= i;
	}
	printf("%lld\n", pot);
}

