#include <bits/stdc++.h>
using namespace std;
const int maxN = 1008611;

// O(nlogn) : O(n)
void merge_sort(long long *arr, int left, int right)
{
	if (left==right) return;
	
	int mid = (left+right) / 2;
	merge_sort(arr, left, mid);
	merge_sort(arr, mid+1, right);
	
	long long *tmp = new long long[right-left+1];
	int i = 0, j = left, k = mid+1;
	while (i <= right-left)
	{
		if (k == right + 1 || (j != mid+1 && arr[j] < arr[k])) {
			tmp[i++] = arr[j++]; 
		}
		else {
			tmp[i++] = arr[k++];
		}
	}
	memcpy(arr+left, tmp, sizeof(long long)*(right-left+1));
	
	delete[] tmp;
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
		merge_sort(arr, 0, n-1);
		for (int i = 0; i < n; ++i)
		{
			if (i) putchar(' ');
			printf("%lld", arr[i]);
		}
		putchar('\n');
	}
}
