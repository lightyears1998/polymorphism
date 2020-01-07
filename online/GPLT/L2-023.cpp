#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

const int maxN = 505;

int v, e, k;
int color[maxN];
vector<pi> edge;
set<int> kinds;

bool check()
{	
	for (pi e : edge) 
	{
		if (color[e.first] == color[e.second]) 
			return false;
	}
	return true;
}

int main()
{
	cin >> v >> e >> k;
	for (int i=0; i<e; ++i) {
		int a, b; cin >> a >> b;
		edge.push_back({a, b});
	}
	
	int n; cin >> n;
	while (n--) 
	{
		kinds.clear();
		for (int i=1; i<=v; ++i) {
			cin >> color[i];
			kinds.insert(color[i]);
		}
		if (kinds.size() != unsigned(k)) {
			cout << "No" << endl; continue;
		}
		cout << (check() ? "Yes" : "No") << endl;
	}
}
