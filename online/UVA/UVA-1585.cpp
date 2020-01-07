#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	while (n--)
	{
		string s; cin >> s;
		int sum = 0, cnt = 0;
		for (char c : s)
		{
			if (c == 'O') cnt++, sum += cnt;
			else cnt = 0;
		}
		cout << sum << endl;
	}
}

