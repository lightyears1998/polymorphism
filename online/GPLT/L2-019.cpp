#include <bits/stdc++.h>
using namespace std;

map<string, bool> followed;
map<string, int> user;
vector<string> secret;

int main()
{
	int n; cin >> n;
	while (n--) {
		string s; cin >> s;
		followed[s] = true;
	}
	
	double tot = 0;
	int m; cin >> m;
	for (int i=0; i<m; ++i) {
		string s; int likes; cin >> s >> likes;
		user[s] = likes; tot += likes;
	}
	double avg = tot/m;
	for (auto it = user.begin(); it != user.end(); ++it) {
		string s = it->first; int likes = it->second;
		if (likes > avg && !followed[s]) 
			secret.push_back(s);
	}
	sort(secret.begin(), secret.end());
	
	if (secret.size()) {
		for (string &s: secret) cout << s << endl;
	}
	else cout << "Bing Mei You" << endl;
}
