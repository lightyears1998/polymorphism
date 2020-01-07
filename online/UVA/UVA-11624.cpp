#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using pt = pair<int, int>;

const int INF = 0x3F3F3F3F;
const int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

int r, c;
char pic[1010][1010];
queue<pt> fque, jpos;
int jtme[1010][1010], ftme[1010][1010];

bool legal(int x, int y)
{
	bool ok = true;
	if (x < 1 || x > r || y < 1 || y > c) ok = false;
	return ok;
}

bool atedge(int x, int y)
{
	bool ok = false;
	if (x == 1 || x == r || y == 1 || y == c) ok = true;
	return ok;
}

void fire()
{
	while (fque.size())
	{
		pt cur = fque.front(); fque.pop();
		int cx = cur.first, cy = cur.second;
		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + dir[i][0], ny = cy + dir[i][1];
			if (legal(nx, ny) && pic[nx][ny] != '#' && ftme[nx][ny] > ftme[cx][cy]+1)
			{
				ftme[nx][ny] = ftme[cx][cy]+1;
				fque.push({nx, ny});
			}
		}
	}
}

void escape()
{	
	while (jpos.size())
	{
		pt cur = jpos.front(); jpos.pop();
		int cx = cur.first, cy = cur.second;
		
		if (atedge(cx, cy)) {
			cout << jtme[cx][cy] + 1 << endl;
			return;
		}
		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + dir[i][0], ny = cy + dir[i][1];
			if (legal(nx, ny) && pic[nx][ny] != '#' && jtme[nx][ny] > jtme[cx][cy]+1)
			{
				jtme[nx][ny] = jtme[cx][cy] + 1;
				if (jtme[nx][ny] < ftme[nx][ny])
					jpos.push({nx, ny});
			}
		}
	}
	puts("IMPOSSIBLE");
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif 
	
	int t; cin >> t;
	while (t--)
	{
		cin >> r >> c;
		memset(ftme, 0x3F, sizeof(ftme));
		memset(jtme, 0x3F, sizeof(jtme));
		while (jpos.size()) jpos.pop();
		
		for (int i = 1; i <= r; ++i)
		{
			for (int j = 1; j <= c; ++j)
			{
				cin >> pic[i][j];
				if (pic[i][j] == 'F') {
					fque.push({i, j}); ftme[i][j] = 0;
				}
				if (pic[i][j] == 'J') {
					jpos.push({i, j}); jtme[i][j] = 0;
				}
			}
		}
		fire();
		escape();
	}
} 

