#include <bits/stdc++.h>
using namespace std;
using LL = long long; 

const int maxN = 50050;
LL num[maxN];

int main()
{
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%lld", &num[i]);
	}
	
	LL sum = accumulate(num, num+n, 0LL);
	
	LL mx = 0, cur = 0;
	for (int i=0; i<n; ++i)	{
		cur = max(0LL, cur+num[i]);
		mx  = max(cur, mx);
	}
	
	LL mn = 0; cur = 0;
	for (int i=0; i<n; ++i) {
		cur = min(0LL, cur+num[i]);
		mn  = min(cur, mn);
	}
	
	printf("%lld\n", max(mx, sum-mn));
}
