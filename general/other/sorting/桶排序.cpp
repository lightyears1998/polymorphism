#include <bits/stdc++.h>
using namespace std;

// O(n)
// The value of the elements must be unique.
void bulket_sort(vector<long long> &vec)
{
	vector<long long> bulket[10];
	long long mx = *max_element(vec.begin(), vec.end());
	long long mn = *min_element(vec.begin(), vec.end());
	for (auto cur : vec)
	{
		int i = floor((double)(cur-mn) / (mx-mn));
		if (i < 0) i = 0;
		if (i > 9) i = 9;
		bulket[i].push_back(cur); 
	}
	for (int i = 0; i < 10; ++i)
	{
		if (bulket[i].size() <= 1) continue;
		bulket_sort(bulket[i]);
	}
	vec.clear();
	for (int i = 0; i < 10; ++i)
	{
		copy(bulket[i].begin(), bulket[i].end(), back_inserter(vec));
	}
}

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
		
		vector<long long> arr;
		while (n--)
		{
			long long cur; scanf("%lld", &cur);
			arr.push_back(cur);
		}
		bulket_sort(arr);
		for (unsigned i = 0; i < arr.size(); ++i)
		{
			if (i) putchar(' ');
			printf("%lld", arr[i]);
		}
		putchar('\n');
	}
} 

