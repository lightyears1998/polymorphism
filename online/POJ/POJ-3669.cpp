#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

#define pt pair<int, int>

const int maxN = 304;
const int INF  = 0x3F3F3F3F;
const int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

int m;
int pic[maxN][maxN];
int tme[maxN][maxN];
queue<pt> que;

bool legal(int x, int y) {
	return x>=0 && x<maxN && y>=0 && y<maxN;
}

bool safe(int x, int y) {
	return pic[x][y] == INF;
}

void bfs()
{
	if (pic[0][0] == 0) {
		puts("-1"); return;
	}
	if (safe(0, 0)) {
		puts("0"); return;
	}
	
	tme[0][0] = 0; que.push({0, 0});
	while (!que.empty())
	{
		pt cur = que.front(); que.pop();
		int cx = cur.first, cy = cur.second;

		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + dir[i][0], ny = cy + dir[i][1];
			if (legal(nx, ny) && tme[nx][ny] > tme[cx][cy]+1) {
				tme[nx][ny] = tme[cx][cy] + 1;
				if (safe(nx, ny)) {
					printf("%d\n", tme[nx][ny]); return;
				}
				if (tme[nx][ny] < pic[nx][ny])
					que.push({nx, ny});
			}
		}
	}
	puts("-1");
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	
	while (scanf("%d", &m) == 1)
	{
		memset(pic, 0x3F, sizeof(pic));
		memset(tme, 0x3F, sizeof(tme));
		while (!que.empty()) que.pop();
		
		while (m--)
		{
			int x, y, t; scanf("%d%d%d", &x, &y, &t);
			pic[x][y] = min(pic[x][y], t);
			for (int i = 0; i < 4; ++i) {
				int dx = x + dir[i][0], dy = y + dir[i][1];
				if (legal(dx, dy)) pic[dx][dy] = min(pic[dx][dy], t);
			}
		}
		
		bfs();
	}
}

