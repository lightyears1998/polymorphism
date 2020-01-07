#include <bits/stdc++.h>
using namespace std;

const int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int h, w, tot;
char pic[110][110];

void dfs(int i, int j, char type)
{
	pic[i][j] = '.';
	for (int k = 0; k < 4; ++k)
	{
		int ni = i + dir[k][0], nj = j + dir[k][1];
		if (ni>=0 && ni<h && nj>=0 && nj<w && pic[ni][nj]==type) 
			dfs(ni, nj, type);
	}
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin); 
	#endif
	
	while (scanf("%d%d", &h, &w) == 2 && h)
	{
		tot = 0;
		for (int i = 0; i < h; ++i)
			scanf("%s", pic[i]);

		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				if (pic[i][j] != '.') ++tot, dfs(i, j, pic[i][j]);
		printf("%d\n", tot);
	}
} 


