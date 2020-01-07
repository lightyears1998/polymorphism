#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	while (n--)
	{
		string s; cin >> s;
		string ans = s;
		for (int i = 1; i < s.size(); ++i)
		{
			string cur;
			for (int j = 0; j < s.size(); ++j)
				cur += s[(i + j) % s.size()];
			if (cur < ans) ans = cur;
		}
		cout << ans << endl;
	}
}

