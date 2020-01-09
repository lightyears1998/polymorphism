#include <bits/stdc++.h>
using namespace std;
const int maxN = 1008611; 

int t, n; 
long long arr[maxN]; 

// O(nlogn) : O(n)
void quick_sort(long long *arr, int left, int right)
{
	if (left >= right) return;
	
	long long privot = arr[left];
	int i = left+1, j = right;
	while (i <= j)
	{
		while (i<=right && arr[i] < privot) ++i;
		while (j>=left+1 && arr[j] >= privot) --j;
		if (i<j) swap(arr[i], arr[j]);
	}
	swap(arr[left], arr[j]);
	quick_sort(arr, left, j-1);
	quick_sort(arr, i, right);
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout); 
	#endif
	
	scanf("%d", &t); 
	while (t--)
	{
		scanf("%d", &n); 
		for (int i=0; i<n; ++i)
		{
			scanf("%lld", &arr[i]); 
		}
		quick_sort(arr, 0, n-1);
		for (int i=0; i<n; ++i)
		{
			if (i) putchar(' ');
			printf("%lld", arr[i]); 
		} 
		putchar('\n'); 
	} 
}
