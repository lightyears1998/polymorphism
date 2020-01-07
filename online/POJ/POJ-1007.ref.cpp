#include <cstdio>
#include <algorithm>
using namespace std;

// 映射
// https://vjudge.net/solution/1051124

char str[100][55];
int ref[100];

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%s", str[i]);
		for (int j = 0; j < n; ++j)
			for (int k = j+1; k < n; ++k) if (str[i][j] > str[i][k])
				++ref[i];
		ref[i] = 100*ref[i] + i;
	}
	sort(ref, ref+m);
	for (int i = 0; i < m; ++i)
		puts(str[ref[i]%100]);
}
