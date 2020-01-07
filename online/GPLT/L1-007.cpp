#include <bits/stdc++.h>
using namespace std;

map<char, string> mp {
	{'-', "fu"},
	{'0', "ling"}, {'1', "yi"}, {'2', "er"}, {'3', "san"}, {'4', "si"},
	{'5', "wu"}, {'6', "liu"}, {'7', "qi"}, {'8', "ba"}, {'9', "jiu"},
};

int main()
{
	string s; cin >> s;
	for (unsigned i=0; i<s.size(); ++i) {
		if (i) cout << ' ';
		cout << mp[s[i]];
	}
	cout << endl;
}
