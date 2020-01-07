#include <bits/stdc++.h>
using namespace std;
using pt = pair<int, int>;

const int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

int h, w, n, si, sj;
bool done; int tot; 
char pic[1010][1010];
int tme[1010][1010];
queue<pt> que;

bool ok(int x, int y)
{
	return x>=0 && x<h && y>=0 && y<w && pic[x][y] != 'X';
}

void bfs()
{
	int gained = 0;
	for (int tg = 1; tg-gained == 1 && tg <= n; ++tg)
	{
		memset(tme, 0x3F, sizeof(tme)); tme[si][sj] = 0;
		while (!que.empty()) que.pop(); que.push({si, sj});
		
		while (!que.empty())
		{
			pt cur = que.front(); que.pop();
			int cx = cur.first, cy = cur.second;
			
			if (pic[cx][cy] == tg+'0') {
				tot += tme[cx][cy]; si = cx, sj = cy;
				++gained; break;
			}
			for (int i = 0; i < 4; ++i)
			{
				int nx = cx + dir[i][0], ny = cy + dir[i][1];
				if (ok(nx, ny) && tme[nx][ny] > tme[cx][cy]+1) {
					tme[nx][ny] = tme[cx][cy]+1;
					que.push({nx, ny});
				}
			}
		}
	}
	if (gained == n) done = true;
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	
	scanf("%d%d%d", &h, &w, &n);
	for (int i = 0; i < h; ++i) 
	{
		scanf("%s", pic[i]);
		for (int j = 0; j < w; ++j)
		{
			if (pic[i][j] == 'S') si = i, sj = j;
		}
	}
	
	bfs();
	if (done)
		printf("%d\n", tot);
	else
		puts("-1");
} 

