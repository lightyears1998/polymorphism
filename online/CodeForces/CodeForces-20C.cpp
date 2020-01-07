#include <bits/stdc++.h>
using namespace std;

// 进一步优化
// ConanYu - https://vjudge.net/solution/12230381
// 可以用pair来优化，避免定义p

const long long INF = 0x3F3F3F3F3F3F3F3F;

struct p
{
	int x;
	long long dis;

	bool operator < (const p& oth) const
	{
		if (dis != oth.dis)
			return dis > oth.dis;
		else
			return x < oth.x;
	}
};

struct edge
{
	int dst;
	long long dis;
};

int n, m;
int front[100100];
long long dis[100100];
vector<edge> g[100100];
priority_queue<p, vector<p>, less<p>> q;

void dijkstra()
{
	dis[1] = 0;
	q.push({1, 0});
	while (!q.empty())
	{
		p cur = q.top(); q.pop();
		int src = cur.x;

		if (dis[src] < cur.dis) continue;
		if (src == n) break;

		for (int i = 0; i < g[src].size(); ++i)
		{
			int dst = g[src][i].dst;
			if (dis[dst] > dis[src] + g[src][i].dis)
			{
				dis[dst] = dis[src] + g[src][i].dis;
				front[dst] = src;
				q.push({dst, dis[dst]});
			}
		}
	}

	if (dis[n] != INF)
	{
		int ans[100100], cur = n, i = 0;
		while (cur != 0)
		{
			ans[i++] = cur;
			cur = front[cur];
		}
		while (--i >= 0)
			printf("%d ", ans[i]);
		printf("\n");
	}
	else printf("-1\n");
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif


	while (scanf("%d%d", &n, &m) == 2)
	{
		memset(dis, 0x3F, sizeof(dis));
		for (int i = 1; i <= n; ++i)
		{
			front[i] = 0;
			g[i].push_back({i, 0});
		}

		while (m--)
		{
			int a, b; scanf("%d%d", &a, &b);
			long long w; scanf("%lld", &w);
			g[a].push_back({b, w});
			g[b].push_back({a, w});
		}

		dijkstra();
	}
}
