#include <bits/stdc++.h>
using namespace std;

string a, b;

int main()
{
	while (getline(cin, a) && a != "#") 
	{
		getline(cin, b);
		for (char c : a)
		{
			int cnt = 0;
			for (char d : b) {
				if (c == d) ++cnt;
			}
			cout << c << ' ' << cnt << endl;
		}
	}
}

