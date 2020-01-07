#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxN = 50050;

struct edge {
	int s, d, w;
	bool operator <(const edge &e) const {
		return w < e.w;
	}
} e[maxN];

int n, m, cnt;
int fa[maxN];

void init() {
	cnt = 0;
	for (int i=0; i<n+m; ++i) fa[i] = i;
}

int find(int x) {
	return fa[x] == x ? fa[x] : fa[x]=find(fa[x]);
}

bool query(int x, int y) {
	return find(x) == find(y);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	fa[a] = b;
}

void addedge(int x, int y, int k) {
	edge &cur = e[cnt++];
	cur.s = x, cur.d = y, cur.w = k;
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		int r; scanf("%d%d%d", &n, &m, &r); 
		init();
		
		while (r--) {
			int x, y, k; scanf("%d%d%d", &x, &y, &k);
			y += n;
			k = -k;
			addedge(x, y, k);
		}
		
		sort(e, e+cnt);
		
		int ans = 0;
		for (int i=0; i<cnt; ++i) {
			edge cur = e[i];
			if (!query(cur.s, cur.d)) {
				merge(cur.s, cur.d);
				ans += cur.w;
			}
		}
		
		printf("%d\n", 10000*(n+m) + ans);
	}
} 
