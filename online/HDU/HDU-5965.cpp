// 扫雷 - 枚举后单调
// Reference - https://blog.csdn.net/Stray_Lambs/article/details/53113676

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int maxN = 10010;
const int mod  = 100000007;

long long dp[maxN];
int mine[maxN];

char buf[maxN];

int main()
{
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%s", buf);
		
		int len = 0;
		for (int i=0; buf[i]; ++i) {
			mine[i+1] = buf[i]-'0';
			++len;
		}
		
		LL ans = 0; bool flag;
		for (int per=0; per<3; ++per) {
			dp[1]=per; flag = true;
			for (int i=2; i<=len; ++i) {
				dp[i] = mine[i-1]-dp[i-1]-dp[i-2];
				if (!(dp[i]>=0 && dp[i]<3)) {
					flag = false; break;
				}
			}
			if (flag && dp[len]+dp[len-1] == mine[len]) {
				LL nxt = 1;
				for (int i=1; i<=len; ++i) {
					if (dp[i] == 1) nxt*=2, nxt%=mod;
				}
				ans += nxt, ans %= mod;
			}
			else continue;
		}
		printf("%lld\n", ans);
	}
} 
