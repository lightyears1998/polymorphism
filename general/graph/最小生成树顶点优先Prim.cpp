#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using dv = pair<LL, int>;

const int maxN = 1010;
const LL  INF  = 0x3F3F3F3F3F3F3F3F;

int n, m;
LL edge[maxN][maxN];
LL dis[maxN];
bool selected[maxN];
priority_queue<dv, vector<dv>, greater<dv>> que;

LL prim()
{
	LL ans = 0;
	
	dis[1] = 0, selected[1] = true;
	for (int i = 2; i <= n; ++i)
	{
		dis[i] = edge[1][i];
		que.push({dis[i], i});
	}
	while (que.size())
	{
		dv cur = que.top(); que.pop();
		if (selected[cur.second]) continue;
		
		ans += cur.first, selected[cur.second] = true;
		for (int i = 1; i <= n; ++i) if(!selected[i])
		{
			if (dis[i] > edge[cur.second][i])
			{
				dis[i] = edge[cur.second][i];
				que.push({dis[i], i});
			}
		}
	}
	return ans;
}

int main()
{
	cin >> n >> m;
	memset(dis, 0x3F, sizeof(dis));
	memset(edge, 0x3F, sizeof(edge));
	for (int i = 0; i < m; ++i)
	{
		LL a, b, w; cin >> a >> b >> w;
		edge[a][b] = min(edge[a][b], w);
		edge[b][a] = edge[a][b];
	}
	cout << prim() << endl;
}

