#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main()
{
	LL n; cin >> n;
	int ans = 0;
	for (LL i=0, j=(LL)(sqrt(n)+1); i<=j; ) {
		LL sum = i*i + j*j;
		if (sum == n) {
			cout << i << ' ' << j << endl;
			++ans, ++i, --j;
		}
		else if (sum < n) ++i;
		else --j;
	}
	if (!ans) cout << "No Solution" << endl;
}
