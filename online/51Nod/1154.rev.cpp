#include <bits/stdc++.h>
using namespace std;

// Reference: https://blog.csdn.net/u010885899/article/details/50364183
// Reference: https://www.51nod.com/onlineJudge/submitDetail.html#!judgeId=149253

const int INF = 0x3F3F3F3F;
const int maxN = 5050;
char str[maxN];

int dp[maxN];
void solve(int n)
{
	fill(dp, dp+maxN, maxN);
	dp[0] = 0;
	for (int i=1; i<=n; ++i) {
		for (int j=i, k=i; j>0&&k<=n; --j, ++k) {
			if (str[j] == str[k]) {
				dp[k] = min(dp[k], dp[j-1]+1);
			}
			else break;
		}
		for (int j=i, k=i+1; j>0&&k<=n; --j, ++k) {
			if (str[j] == str[k]) {
				dp[k] = min(dp[k], dp[j-1]+1);
			}
			else break;
		}
	}
}

int main()
{
	while (scanf("%s", str+1) == 1) {
		int n = strlen(str+1);
		solve(n);
		printf("%d\n", dp[n]);
	}
}

