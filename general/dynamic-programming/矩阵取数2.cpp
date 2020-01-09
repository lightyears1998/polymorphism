#include <bits/stdc++.h>
using namespace std;

// Important： 
// 处理此类问题，一定要定义清楚横纵坐标的位置!
// 否则找bug将会十分辛苦……  
// 有一类规避坐标的问题的办法，
// 就是当输入的矩阵不是方阵时，将矩阵补充成为方阵，
// 利用对称性，即使坐标对应关系出错，最终的结果也是正确的 
const int maxN = 250;

int n, m;
int bonus[maxN][maxN];
int dp[maxN*2][maxN][maxN]; 

void dump()
{
	for (int s=1; s<= m+n-1; ++s)
	for (int i=1; i<=m; ++i) {
		for (int j=1; j<=m; ++j) {
			cout << dp[s][i][j] << ' ';
		}
		cout << endl;
	}
}

int main()
{
	scanf("%d%d", &m, &n);
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=m; ++j)
			scanf("%d", &bonus[i][j]);
			
	// m = max(m, n); n = max(m, n); // 可以利用的小技巧 
	int step = m+n-1;
	for (int s=1; s<=step; ++s) 
	{
		for (int x1=s; x1>0; --x1) 
		{
			int y1=s+1-x1;
			if (x1>m || y1>n) continue;
			
			for (int x2=s; x2>0; --x2) 
			{
				int y2=s+1-x2;
				if (x2>m || y2>n) continue;
				
				dp[s][x1][x2] = max(dp[s][x1][x2], dp[s-1][x1][x2]);
				dp[s][x1][x2] = max(dp[s][x1][x2], dp[s-1][x1-1][x2]);
				dp[s][x1][x2] = max(dp[s][x1][x2], dp[s-1][x1][x2-1]);
				dp[s][x1][x2] = max(dp[s][x1][x2], dp[s-1][x1-1][x2-1]);
				
				int extra = bonus[y1][x1]; // 此处曾将横纵坐标取反 
				if (x1 != x2) extra += bonus[y2][x2];
				dp[s][x1][x2] += extra;
 			}
		}
	}
	printf("%d\n", dp[step][m][m]);
}
