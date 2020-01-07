#include <cstdio> 
#include <cstring> 
using namespace std;

const int INF = 0x3F3F3F3F;

int n, m;
int pic[25][25], cur[25][25]; 
int ans[25][25], bst[25][25]; 
int cstep, bstep;  

void change(int i, int j)
{
	cur[i-1][j] = 1 - cur[i-1][j];
	cur[i][j-1] = 1 - cur[i][j-1];
	cur[i][j] = 1 - cur[i][j]; 
	cur[i][j+1] = 1 - cur[i][j+1]; 
	cur[i+1][j] = 1 - cur[i+1][j]; 
} 

void search()
{
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (cur[i-1][j]) 
			{
				ans[i][j] = 1, ++cstep; 
				change(i, j); 
			} 
		} 
	}
	
	bool ok = true;
	for (int i = 1; i <= m; ++i)
		if (cur[n][i]) ok = false;
	
	if (ok)
	{
		if (cstep < bstep)
		{
			bstep = cstep;
			memcpy(bst, ans, sizeof(bst));
		} 
	} 
} 

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout); 
	#endif 
	
	while (scanf("%d%d", &n, &m) == 2)
	{
		bstep = INF;
		
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				scanf("%d", &pic[i][j]);
		
		for (int i = 0; i < (1<<m); ++i)
		{
			memcpy(cur, pic, sizeof(cur));
			memset(ans, 0, sizeof(ans));
			cstep = 0; 
			
			for (int j = m; j > 0; --j)
			{
				if (i&(1<<(m-j))) { 
					ans[1][j] = 1, ++cstep; 
					change(1, j);
				}
			}
			search(); 
		} 
		
		if (bstep == INF) printf("IMPOSSIBLE\n");
		else 
		{
			for (int i = 1; i <= n; ++i)
			{
				for (int j = 1; j <= m; ++j)
				{
					printf("%d", bst[i][j]); 
					(j == m) ? printf("\n") : printf(" ");  
				}
			}
		}
	} 
} 
