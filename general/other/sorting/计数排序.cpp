#include <bits/stdc++.h>
using namespace std;
const int maxN = 1008611;

// O(n + k) : O(k)
// This implement can only be used to sort none-negative numbers
void counting_sort(long long *arr, int left, int right)
{
	long long mx = *max_element(arr+left, arr+right+1);
	
	long long *cnt = new long long[mx+1]();
	for (int i = left; i <= right; ++i)
		++cnt[arr[i]];
	for (long long i = 1; i <= mx; ++i)
		cnt[i] += cnt[i-1];
	for (long long i = mx; i; --i)
	{
		while (cnt[i]) arr[--cnt[i] + left] = i;
	}
	delete[] cnt;
}

long long arr[maxN];

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	int t; scanf("%d", &t);
	while (t--)
	{
		int n; scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%lld", &arr[i]);
		}
		counting_sort(arr, 0, n-1);
		for (int i = 0; i < n; ++i)
		{
			if (i) putchar(' ');
			printf("%lld", arr[i]);
		}
		putchar('\n');
	}
}

