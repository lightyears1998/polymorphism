#include <bits/stdc++.h>
using namespace std;

const int maxN = 1234567;

char s[maxN], p[maxN];
int pre[maxN];

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	
	int cnt = 0;
	scanf("%s%s", s+1, p+1);
	
	for (int i = 2, j = 0; p[i]; ++i)
	{
		while (j > 0 && p[i] != p[j+1]) j = pre[j];
		if (p[i] == p[j+1]) ++j;
		pre[i] = j;
	}
	
	for (int i = 1, j = 0; s[i]; ++i)
	{
		while (j > 0 && s[i] != p[j+1]) j = pre[j];
		if (s[i] == p[j+1]) ++j;
		if (!p[j+1]) ++cnt;
	}
	cout << cnt << endl;
} 
