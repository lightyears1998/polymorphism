#include <bits/stdc++.h>
using namespace std; 

int n, mx;
char str[110110];
int len[300000];

void manacher()
{
	len[0] = 1;
	for (int i = 1, j = 0; i < (n << 1) - 1; ++i)
	{
		int p = i >> 1, q = i - p, r = ((j+1)>>1) + len[j] - 1;
		len[i] = r < q ? 0 : min(r - q + 1, len[(j<<1)-i]);
		while (p-len[i] >= 0 && q+len[i]>=0 && str[p-len[i]] == str[q+len[i]])
			++len[i]; 
		if (q + len[i] - 1 > r)
			j = i;
		mx = max(mx, (i&1) ? len[i]*2 : len[i]*2-1);
	}
}

int main()
{
	while (scanf("%s", str) == 1)
	{
		mx = 0, n = strlen(str);
		manacher();
		
		printf("%d\n", mx);
	}
}
