#include <cstdio>
#include <cstring> 
using namespace std;

// 合理剪枝带来性能的巨大提升 

int n, k, tot;
bool occupied[10]; 
char board[10][10];

void search(int x, int placed)
{
	if (placed == k)
	{	
		tot++;
		return;
	}
	if (x == n || k - placed > n - x) return;
	
	for (int i = 0; i < n; ++i)
	{
		if (board[x][i] == '#' && !occupied[i])
		{
			occupied[i] = true;
			search(x + 1, placed + 1);
			occupied[i] = false; 
		}
	}
	search(x + 1, placed); 
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	
	while (scanf("%d%d", &n, &k) && ~n && ~k)
	{
		tot = 0;
		memset(occupied, false, sizeof(occupied)); 
		
		for (int i = 0; i < n; ++i)
			scanf("%s", &board[i]); 
		
		search(0, 0);
		printf("%d\n", tot); 
	}
}
