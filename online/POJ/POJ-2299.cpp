#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxN = 500050;
map<int, int> rfc;
int bit[maxN], num[maxN];

int lowbit(int x)
{
	return x&(-x);
}

void add(int x)
{
	while (x < maxN)
	{
		++bit[x];
		x += lowbit(x);
	}
}

int query(int x)
{
	int ans = 0;
	while (x) {
		ans += bit[x];
		x -= lowbit(x);
	}
	return ans;
}

int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n)
	{
		rfc.clear();
		memset(bit, 0, sizeof(bit));
		
		for (int i = 1; i <= n; ++i) scanf("%d", &num[i]), rfc[num[i]] = i;
		sort(num+1, num+1+n);
		
		long long ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			add(rfc[num[i]]);
			ans += i - query(rfc[num[i]]);
		}
		printf("%lld\n", ans);
	}
}
