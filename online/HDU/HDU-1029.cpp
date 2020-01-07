#include <bits/stdc++.h>

// 思路小结：
// 1.统计
// 2.排序
// 3.递推关系

// 三种思路参考：
// http://blog.csdn.net/to_be_better/article/details/50557796

// 思路3
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		int cnt = 0, ans; scanf("%d", &ans);
		while (--n)
		{
			int t; scanf("%d", &t);
			if (t == ans) ++cnt;
			else if (--cnt < 0) ans = t, cnt = 0;
		}
		printf("%d\n", ans);
	}
}
