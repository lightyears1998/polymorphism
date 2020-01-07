#include <bits/stdc++.h>
using namespace std;

int cnt[10];

int main()
{
	int n; cin >> n;
	while (n--)
	{
		memset(cnt, 0, sizeof(cnt));
		int t; cin >> t;
		
		string s;
		for (int i = 1; i <= t; ++i)
			s += to_string(i);
		
		for (char c : s)
		{
			++cnt[c - '0'];
		}	
		
		for (int i = 0; i < 10; ++i)
		{
			if (i) cout << ' ';
			cout << cnt[i];
		}
		cout << endl;
	}	
}
