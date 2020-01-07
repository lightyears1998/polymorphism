#include <cstdio>
using namespace std;

const int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

int w, h, tot;
char pic[25][25];

bool ok(int x, int y)
{
	return x >= 0 && x < h && y >= 0 && y < w && pic[x][y] != '#';
} 

void dfs(int i, int j)
{
	pic[i][j] = '#'; ++tot;
	for (int k = 0; k < 4; ++k) 
	{
		int ni = i + dir[k][0], nj = j + dir[k][1];
		if (ok(ni, nj)) dfs(ni, nj); 
	}
}

int main()
{
	while (scanf("%d%d", &w, &h) == 2 && w)
	{
		tot = 0;
		for (int i = 0; i < h; ++i)
		{
			scanf("%s", pic[i]);
		}
		
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				if (pic[i][j] == '@') dfs(i, j);
					
		printf("%d\n", tot);
	}
} 

