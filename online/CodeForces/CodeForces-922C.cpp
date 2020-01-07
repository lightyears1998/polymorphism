#include <bits/stdc++.h>
using namespace std;
using LL = unsigned long long;

// Editorial:
// http://codeforces.com/blog/entry/57605

int main()
{
	LL n, k; cin >> n >> k;
	
	bool flag = true;
	if (k > 43) flag = false;
	else 
	{
		for (LL i = k; i; --i) if (n%i != i-1)
		{
			flag = false;
		}
	}
	cout << (flag ? "YES" : "NO") << endl;
}

