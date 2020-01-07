#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int len[110];
char buf1[110], buf2[110];
char str[110][110];

void prepare(char *str, int len)
{
	strncpy(buf1, str, len); buf1[len] = 0;
	
	buf2[len] = 0;
	for (int k = len; k; --k)
		buf2[k-1] = str[len-k];
}

bool judge(char *str1, char *str2, int now)
{
	return (strstr(str[now], str1) != NULL || strstr(str[now], str2) != NULL);
}

int main()
{	
	int t; scanf("%d", &t);
	while (t--)
	{
		int n; scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%s", str[i]);
		
		int idx = 0;
		for (int i = 0, mn = 9999; i < n; ++i)
			if ((len[i] = strlen(str[i])) < mn) {
				mn = len[i];
				idx = i;
			}
		
		bool done = false;
		for (int length = len[idx]; !done && length; --length)
		{
			for (int bgn = 0; bgn+length-1<len[idx]; ++bgn)
			{
				prepare(str[idx]+bgn, length);
				
				bool ok = true;
				for (int j = 0; ok && j < n; ++j)
					ok = judge(buf1, buf2, j);
					
				if (ok) {
					printf("%d\n", length);
					done = true; 
					break;
				}
			}
		}
		if (!done) printf("%d\n", 0);
	}
}
