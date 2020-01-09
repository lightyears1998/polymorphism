#include <bits/stdc++.h>
using namespace std;
const int maxN = 1008611; 

int t, n; 
long long arr[maxN]; 

void perc_down(long long *arr, int i, int n)
{
	auto lson = [](int x){ return 2*x+1; };
	auto rson = [](int x){ return 2*x+2; }; 
	while (true)
	{
		int l = lson(i), r = rson(i);
		if (l<n) {
			int mx = (r<n && arr[r]>arr[l] ? r : l);
			if (arr[i] < arr[mx]) {
				swap(arr[i], arr[mx]);
				i = mx; 
			} 
			else break; 
		} 
		else break; 
	}
}

// O(nlogn) : O(n)
void heap_sort(long long *arr, int n)
{
	for (int i = n-1; i>=0; --i)
	{
		perc_down(arr, i, n); 
	}
	for (int i = n-1; i; --i)
	{
		swap(arr[0], arr[i]);
		perc_down(arr, 0, i); 
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
		heap_sort(arr, n);
		for (int i=0; i<n; ++i)
		{
			if (i) putchar(' ');
			printf("%lld", arr[i]); 
		}
		putchar('\n'); 
	}
}

