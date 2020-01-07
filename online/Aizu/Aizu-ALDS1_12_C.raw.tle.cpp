// ConanYu's https://vjudge.net/solution/13220749
// semon0x29a's https://vjudge.net/solution/13218148
// TLE - 不带邻接表的Dijkstra在面对大数据的时候毫无用武之地

#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using pi = pair<int, int>;

const int INF = 0x3F3F3F3F;
const int maxN = 10010;

int n;
bool mark[maxN];
LL dis[maxN];
map<pi, LL> path;

void init() {
	memset(dis, 0x3F, sizeof(dis));
	for (int i=0; i<n; ++i) path[{i, i}] = 0;
}

void dijkstra() {
	dis[0] = 0;
	for (int i=0; i<n; ++i) {
		int marker = 0, amin = INF;
		for (int i=0; i<n; ++i) if (!mark[i]) {
			if (dis[i] < amin) {
				amin = dis[i];
				marker = i;
			}
		}
		mark[marker] = true;
		for (int i=0; i<n; ++i) if (!mark[i]) {
			if (path.count({marker, i}))
			if (dis[i] > dis[marker] + path[{marker, i}])	
				dis[i] = dis[marker] + path[{marker, i}];
		}
	}
}

int main()
{	
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif 

	scanf("%d", &n);
	init();
	
	for (int i=0; i<n; ++i) 
	{
		int u, k; scanf("%d%d", &u, &k);
		while (k--) {
			int v; LL c; scanf("%d%lld", &v, &c);
			if (path.count({u, v}))
				path[{u, v}] = min(path[{u, v}], c);
			else path[{u, v}] = c;
		}
	}
	
	dijkstra();
	for (int i=0; i<n; ++i) {
		printf("%d %lld\n", i, dis[i]);
	}
}
