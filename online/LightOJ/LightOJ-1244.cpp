#include <bits/stdc++.h>
using namespace std;

const int mod = 10007;
const int maxN = 10007;
int ans[maxN];

int main()
{
	ans[0] = 1, ans[1] = 1, ans[2] = 2;
	for (int i = 3; i < maxN; ++i)
	{
		ans[i] = 2*ans[i-1] + ans[i-3];
		ans[i] %= mod;
	}
	
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; ++i) 
	{
		int in; scanf("%d", &in);
		printf("Case %d: %d\n", i, ans[in%10006]);
	} 
}
