#include <bits/stdc++.h>
using namespace std;

map<string, string> mp{
	{"ChuiZi", "Bu"}, {"JianDao", "ChuiZi"}, {"Bu", "JianDao"}, 
};

int main()
{
	int k; cin >> k;
	
	int cnt = k;
	string s; while (cin >> s) {
		if (s == "End") break;
		if (cnt == 0) {
			cout << s << endl;
			cnt = k;
		} 
		else {
			cout << mp[s] << endl;
			--cnt;
		}
	}
}
