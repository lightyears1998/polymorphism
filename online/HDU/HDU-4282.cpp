#include <bits/stdc++.h>
using namespace std;
using LL = long long;

// 使用位移运算符要小心
// 1<<32, 1LL<<32

LL record[50000][32];

void init()
{
	for (int i = 1; i < 50000; ++i)
	{
		record[i][1] = i;
		for (int j = 2; j < 32; ++j)
		{
			LL tmp = record[i][j-1] * record[i][1];
			if (tmp > (1LL<<31)) break;
			record[i][j] = tmp;
		}
	}
}

bool ok(int x, int z, LL res)
{
	int l = x + 1, r = 49999;
	while (l <= r)
	{
		int mid = (l+r)/2;
		if (record[mid][z] == 0)
			r = mid-1;
		else if (record[mid][z] + x*mid*z == res)
			return true;
		else if (record[mid][z] + x*mid*z < res)
			l = mid+1;
		else r = mid-1;
	}

	return false;
}

int main()
{
	init();

	int k;
	while (scanf("%d", &k) == 1 && k)
	{
		int cnt = 0;
		for (int z = 2; z < 32; ++z)
		{
			for (int x = 1; x < 50000; ++x)
			{
				LL res = k - record[x][z];
				if (res <= 0) break;
				if (ok(x, z, res)) ++cnt;
			}
		}

		printf("%d\n", cnt);
	}
}
