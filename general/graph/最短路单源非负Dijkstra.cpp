// Dijkstra - 无负权边图单源最短路
// 输入起点，终点，边的权重，运行算法
// 算法执行的结果存放在dis[t]中
const int INF = 0x3F3F3F3F;
int n, m, s, t;
int path[220][220];
int dis[220];
bool vis[220];

void dijkstra()
{
	memset(dis, 0x3F, sizeof(dis));
	memset(vis, false, sizeof(vis));
	dis[s] = 0;
	
	for (int i = 0; i < n && !vis[t]; ++i)
	{
		int marker = s, amin = INF;
		for (int j = 0; j < n; ++j) if (!vis[j])
		{
			if (dis[j] < amin) {
				marker = j;
				amin = dis[j];
			}
		}
		vis[marker] = true;
		for (int j = 0; j < n; ++j) if (!vis[j])
			dis[j] = min(dis[j], dis[marker] + path[marker][j]);
	}
}
