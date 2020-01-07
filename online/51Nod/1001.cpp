#include <bits/stdc++.h>
using namespace std;

long long num[50050];

int main()
{
	long long n, k; cin >> k >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];
	sort(num, num+n);
	
	int ans = 0;
	for (int i=0, j=n-1; i<j; ) {
		if (num[i]+num[j] == k) {
			cout << num[i] << ' ' << num[j] << endl;
			++ans, ++i, --j;
		}
		else if (num[i]+num[j] > k) --j;
		else ++i;
	}
	if (!ans) cout << "No Solution" << endl;
}
