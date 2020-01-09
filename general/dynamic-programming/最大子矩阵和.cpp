#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int INF  = 0x3F3F3F3F;
const int maxN = 550;

int n, m;
LL mat[maxN][maxN];
LL colsum[maxN][maxN];

int main()
{
	scanf("%d%d", &m, &n);
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			scanf("%lld", &mat[i][j]);	
			colsum[i][j] = colsum[i-1][j] + mat[i][j];
		}
	}
	
	LL ans = 0;
	for (int i=1; i<=n; ++i) {
		for (int j=i; j<=n; ++j) {	
			LL cur = 0;
			for (int k=1; k<=m; ++k) {
				LL nxt = colsum[j][k] - colsum[i-1][k];
				cur = max(cur+nxt, 0LL);
				ans = max(cur, ans);
			}
		}
	}
	printf("%lld\n", ans);
}
