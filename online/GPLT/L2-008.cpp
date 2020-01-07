#include <bits/stdc++.h>
using namespace std;

char str[1010];

int main()
{
	fgets(str, sizeof(str), stdin);
	
	int mx = 1;
	for (int i=0; str[i]!='\n'; ++i)
	{
		int a=i, b=i;
		while (str[b]==str[b+1]) ++b;
		int len = b-a+1; i = b;
		
		while (a>0 && str[b+1]!='\n' && str[a-1]==str[b+1]) --a, ++b, len += 2;
		mx = max(mx, len);
	}
	printf("%d\n", mx);
}
