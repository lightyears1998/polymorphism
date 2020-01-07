#include <bits/stdc++.h>
using namespace std;
using info = pair<string, int>;

map<int, info> mp;

int main()
{
	int n; cin >> n;
	while (n--) {
		string s; int src, dst;
		cin >> s >> src >> dst;
		mp[src] = {s, dst};
	}
	
	cin >> n;
	while (n--) {
		int q; cin >> q;
		cout << mp[q].first << ' ' << mp[q].second << endl;
	}
}
