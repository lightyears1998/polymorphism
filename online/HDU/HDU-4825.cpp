#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int cnt = 0;
const int maxN = 100100;

struct 
{
	int nxt[2];
} trie[10001000];

int init()
{
	return ++cnt;
}

void insert(LL n)
{
	int cur = 0;
	for (int i = 31; i>=0; --i)
	{
		int id = (n&(1LL<<i) ? 1 : 0);
		if (!trie[cur].nxt[id]) trie[cur].nxt[id] = init();
		cur = trie[cur].nxt[id];
	}
}

void query(LL n)
{
	LL ans = 0; int cur = 0;
	for (int i = 31; i>=0; --i)
	{
		int id = (n&(1LL)<<i ? 1 : 0);
		if (trie[cur].nxt[(1-id)]) {
			ans = (ans<<1) + (1-id);
			cur = trie[cur].nxt[(1-id)];
		}
		else {
			ans = (ans<<1) + id;
			cur = trie[cur].nxt[id];
		}
	}
	printf("%lld\n", ans);
}

int main()
{
	int t; scanf("%d", &t);
	for (int kase = 1; kase <= t; ++kase)
	{
		cnt = 0;
		memset(trie, 0, sizeof(trie));
		
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			LL k; scanf("%lld", &k);
			insert(k);
		}
		
		printf("Case #%d:\n", kase);
		for (int i = 0; i < m; ++i) {
			LL k; scanf("%lld", &k);
			query(k);
		}
	}
}
