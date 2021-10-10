#include <bits/stdc++.h>
using namespace std;
const int maxN = 1008611;

void sleep()
{
	long long ms = maxN;
	while (--ms);
}

// O(∞) : O(n)
void sleep_sort(long long *arr, int n)
{
	int a = rand()*rand() % n, b = rand()*rand() % n;
	swap(arr[a], arr[b]);

	bool ok = true;
	for (int i = 0; i < n-1; ++i)
	{
		if (arr[i]>arr[i+1]) ok = false;
 	}
	if (ok) return;
	sleep(); sleep_sort(arr, n);
}

long long arr[maxN];

int main()
{
	#ifdef IWannaSleepTillThisProcessFinished
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
		sleep_sort(arr, n);
		for (int i = 0; i < n; ++i)
		{
			if (i) putchar(' ');
			printf("%lld", arr[i]);
		}
		putchar('\n');
	}
}
