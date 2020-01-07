#include <bits/stdc++.h>
using namespace std;
 
char str[100100];

int main()
{
	while (scanf("%s", str) == 1) 
	{
		int mx = 1;
		for (int i=0; str[i]; ++i) 
		{
			int p=i, q=i;
			while (str[q]==str[q+1]) ++q;
			i = q;
			
			while (p-1>=0 && str[q+1] && str[p-1]==str[q+1]) --p, ++q;
			mx = max(q-p+1, mx);
		}
		printf("%d\n", mx);
	}
}
 
