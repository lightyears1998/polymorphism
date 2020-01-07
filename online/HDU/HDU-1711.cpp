#include <bits/stdc++.h>
using namespace std;

const int tails = 1e9+7;
const int maxN = 1234567;

int pre[maxN]; 
int s[maxN], p[maxN];  // 文本串、模板串 

void prepare() {
	fill(pre, pre+maxN, -1);
	for (int i=1, j=-1; p[i] != tails; ++i)  
	{
		while (j>=0 && p[i] != p[j+1]) j = pre[j];
		if (p[i] == p[j+1]) ++j;
		pre[i] = j;
	}
}

void kmp(vector<int> &match)
{
	match.clear(); prepare();
	for (int i=0, j=-1; s[i] != tails; ++i) {
		while (j>=0 && s[i] != p[j+1]) j = pre[j];
		if (s[i] == p[j+1]) ++j;
		if (p[j+1] == tails) {  // 匹配成功 
			match.push_back(i-j);
		}
	}
}

int main()
{
	int t; scanf("%d", &t);
	while (t--) {
		int n, m; scanf("%d%d", &n, &m);
		for (int i=0; i<n; ++i) {
			scanf("%d", &s[i]);
		}
		for (int i=0; i<m; ++i) {
			scanf("%d", &p[i]);
		}
		s[n] = p[m] = tails;
		vector<int> rslt; kmp(rslt);
		if (rslt.size()) printf("%d\n", rslt[0]+1);
		else puts("-1");
 	}
}

