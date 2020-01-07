#include <bits/stdc++.h>
using namespace std;
using pt = pair<int, int>;

const int maxN = 1010;
const int INF  = 0x3F3F3F3F;
const int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int n, m, p1, p2, height;
int pic[maxN][maxN];
queue<pt> que;

bool check(pt p)
{
	int x = p.first, y = p.second;
	if (x<0 || x>=n || y<0 || y>=m)
		return false;
	if (pic[x][y > height)
		return false;
	return true;
}

int search()
{
	int cnt = 1;
 	que.push(make_pair(p1-1, p2-1)); pic[p1-1][p2-1] = INF;
	
	while (!que.empty())
	{
		pt cur = que.front(); que.pop();
		for (int i = 0; i < 4; ++i)
		{
			pt nxt = cur;
			nxt.first += dir[i][0], nxt.second += dir[i][1];
			if (check(nxt)) {
				++cnt, pic[nxt.first][nxt.second] = INF;
				que.push(nxt);
			}
		}
	}
	
	return cnt;
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	
	while (scanf("%d%d%d%d", &n, &m, &p1, &p2) == 4)
	{
		while (que.size()) que.pop();		
		
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				scanf("%d", &pic[i][j]);
			}
		}
		height = pic[p1-1][p2-1];
		
		printf("%d\n", search());
	}
}

