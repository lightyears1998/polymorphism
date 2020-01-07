#include <bits/stdc++.h>
using namespace std;

char buf[10240];

int main()
{
	freopen("copycat.in", "r", stdin);
	freopen("copycat.out", "w", stdout);
	
	int i; scanf("%d", &i); getchar();
	while (i--)
	{
		fgets(buf, sizeof(buf), stdin);
		printf("%s", buf);
	}
}

