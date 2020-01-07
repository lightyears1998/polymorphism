#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s; cin >> s;
	
	int g = 0, p = 0, l = 0, t = 0;
	for (char ch : s) {
		if (tolower(ch) == 'g') ++g;
		if (tolower(ch) == 'p') ++p;
		if (tolower(ch) == 'l') ++l;
		if (tolower(ch) == 't') ++t;
	}
	
	while (g || p || l || t) {
		if (g) cout << 'G', --g;
		if (p) cout << 'P', --p;
		if (l) cout << 'L', --l;
		if (t) cout << 'T', --t;
	}
	cout << endl;
}
