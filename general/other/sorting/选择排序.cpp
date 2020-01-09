#include <bits/stdc++.h>
using namespace std;
const int maxN = 1008611; 

int t, n; 
long long arr[maxN]; 

// O(n^2) : O(n)
void select_sort(long long *arr, int left, int right)
{
	for (int i = left; i < right; ++i)
	{
		int mn = i;
		for (int j = i + 1; j <= right; ++j)
		{
			if (arr[j] < arr[mn]) {
				mn = j;
			}
		} 
		swap(arr[i], arr[mn]); 
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
		select_sort(arr, 0, n-1);
		for (int i=0; i<n; ++i)
		{
			if (i) putchar(' ');
			printf("%lld", arr[i]); 
		} 
		putchar('\n'); 
	} 
}
