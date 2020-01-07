#include <bits/stdc++.h>
#include "interaction.h"
using namespace std;

int main()
{
	int n = get_num();
	vector<int> ans(n);
	
	for (int i = 0; i < n; ++i)
	{
		int l = 0, r = 1000010, mid = (l+r)/2, status;
		while ((status = guess(i, mid)) != 0) 
		{
			if (status < 0) l = mid+1;
			else r = mid-1;
			mid = (l+r)/2;
		}
		ans[i] = mid;
	}
	submit(ans);
}
