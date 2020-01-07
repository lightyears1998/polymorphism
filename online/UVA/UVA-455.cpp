#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	while (n--)
	{
		string s; cin >> s;
		
		int i = 0;
		for (i = 1; i <= s.size(); ++i)
		{
			if (s.size() % i) continue;
			
			bool ok = true;
			for (int j = 0; j < s.size(); ++j)
				if (s[j] != s[j % i]) ok = false;
			
			if (ok) break; 
		}
		
		cout << i << endl;
		if (n) cout << endl;
	}
}
