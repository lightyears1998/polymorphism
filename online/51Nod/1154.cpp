#include <bits/stdc++.h>
using namespace std;

// Reference: https://blog.csdn.net/u010885899/article/details/50364183
// Reference: https://www.51nod.com/onlineJudge/submitDetail.html#!judgeId=149253

const int INF = 0x3F3F3F3F;
const int maxN = 5050;
char str[maxN];

bool rev[maxN][maxN];
int dp[maxN];
void solve(int n)
{
	fill(dp, dp+maxN, INF);
	dp[0] = 0;
	for (int i=1; i<=n; ++i) {
		for (int j=i; j>0; --j) {
			if (j==i) {
				rev[j][i] = true;
				dp[i] = min(dp[i], dp[j-1]+1);
			}
			else if (j+1==i && str[i] == str[j]) {
				rev[j][i] = true;
				dp[i] = min(dp[i], dp[j-1]+1);
			}
			else if (str[i] == str[j] && rev[j+1][i-1]){
				rev[j][i] = true;
				dp[i] = min(dp[i], dp[j-1]+1);
			}
		}
	}.
}

int main()
{
	while (scanf("%s", str+1) == 1) {
		int n = strlen(str+1);
		solve(n);
		printf("%d\n", dp[n]);
	}
}

