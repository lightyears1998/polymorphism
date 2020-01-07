#include <cstdio>
#include <algorithm>
using namespace std;

const int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

int h, w, best;
char pic[25][25];

bool legal(int x, int y)
{
	return x>=0 && x<h && y>=0 && y<w;
}

void dfs(int i, int j, int step = 0)
{
	if (step+1 >= best) return;
	for (int k = 0; k < 4; ++k)
	{
		int ni = i, nj = j;
		if (legal(ni+dir[k][0], nj+dir[k][1]) && pic[ni+dir[k][0]][nj+dir[k][1]] != '1')
		{
			while (legal(ni+dir[k][0], nj+dir[k][1])) 
			{
				ni += dir[k][0], nj += dir[k][1];
				if (pic[ni][nj] == '3') {
					best = min(step+1, best);
					break;
				}
				if (pic[ni][nj] == '1') {
					pic[ni][nj] = '0'; 
					dfs(ni-dir[k][0], nj-dir[k][1], step+1);
					pic[ni][nj] = '1';
					break;
				}
			}
		}
	}
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	
	while (scanf("%d%d", &w, &h) == 2 && h)
	{
		best = 11;
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				scanf(" %c", &pic[i][j]);
	
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				if (pic[i][j] == '2') dfs(i, j);
		
		printf("%d\n", (best <= 10 ? best : -1));
	}
}

