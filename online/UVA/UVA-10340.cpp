#include <bits/stdc++.h>
using namespace std;

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	
	string s, t;
	while (cin >> s >> t)
	{
		bool match = true;
		int pos = 0;
		for (char ch : s)
		{
			pos = t.find(ch, pos) + 1;
			if (pos == 0) {
				match = false; break;
			}	
		}
		cout << (match ? "Yes" : "No") << endl;
	}
}
