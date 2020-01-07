#include <bits/stdc++.h>
using namespace std;

const int maxN = 550; 
const int INF  = 0x3F3F3F3F; 

int n, m, s, d;
bool vis[maxN];
int dis[maxN];
int path[maxN][maxN];
int bonus[maxN];
int num[maxN], front[maxN];

int calculate(int k)
{
	int tot = 0;
	while (front[k] != k) {
		tot += bonus[k];
		k = front[k];
	}
	return tot+bonus[s];
}

void dijkstra()
{
	dis[s] = 0; num[s] = 1;
	for (int i=0; i<n; ++i)
	{
		int marker = s, amin = INF;
		for (int j=0; j<n; ++j) if (!vis[j])
			if (dis[j]<amin) {
				marker = j;
				amin = dis[j];
			}
		vis[marker] = true;
		for (int j=0; j<n; ++j) if (!vis[j])
		{
			if (dis[j]==dis[marker]+path[marker][j]) {
				if (calculate(j) < calculate(marker)+bonus[j]) {
					front[j] = marker;
				}
				num[j] += num[marker];
			}
			if (dis[j]>dis[marker]+path[marker][j]) {
				dis[j] = dis[marker]+path[marker][j];
				front[j] = marker;
				num[j] = num[marker];
			}
		}
	}
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &s, &d);
	memset(dis, 0x3F, sizeof(dis));
	memset(path, 0x3F, sizeof(path));
	
	for (int i=0; i<n; ++i)
		scanf("%d", &bonus[i]), 
		path[i][i] = 0,
		front[i] = i;
		
	for (int i=0; i<m; ++i)
	{
		int a, b, t; scanf("%d%d%d", &a, &b, &t);
		path[a][b] = min(path[a][b], t);
		path[b][a] = path[a][b];
	}
	
	dijkstra();
	printf("%d %d\n", num[d], calculate(d));
	
	stack<int> st;
	for (int k = d; front[k] != k; k = front[k]) {
		st.push(k);
	} 
	printf("%d", s);
	while (st.size())
		printf(" %d", st.top()), st.pop();
	putchar('\n');
}
