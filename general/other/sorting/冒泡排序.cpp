#include <bits/stdc++.h>
using namespace std;
const int maxN = 1008611; 

int t, n; 
long long arr[maxN]; 

// O(n^2) : O(n)
void bubble_sort(long long *arr, int left, int right)
{
	for (int i=left; i<=right; ++i)
	{
		for (int j=right; j>i; --j)
		{
			if (arr[j]<arr[j-1]) swap(arr[j], arr[j-1]); 
		} 
	}
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
		bubble_sort(arr, 0, n-1);
		for (int i=0; i<n; ++i)
		{
			if (i) putchar(' ');
			printf("%lld", arr[i]); 
		} 
		putchar('\n'); 
	} 
}
