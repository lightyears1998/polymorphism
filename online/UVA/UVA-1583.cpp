#include <bits/stdc++.h>
using namespace std;

int ans[100100];

int main()
{
	for (int i = 1; i <= 100000; ++i)
	{
		int privot = i, maker = i;
		while (maker)
		{
			privot += maker % 10;
			maker /= 10;
		}
		if (ans[privot] != 0) ans[privot] = min(ans[privot], i);
		else ans[privot] = i;
	}
	
	int n; cin >> n;
	while (n--)
	{
		int t; cin >> t;
		cout << ans[t] << endl;
	}
}
