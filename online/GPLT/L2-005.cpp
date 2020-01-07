#include <bits/stdc++.h>
using namespace std;

set<int> st[55];
vector<int> uni(1e6);

int main()
{
	int n; cin >> n;
	for (int i=1; i<=n; ++i) {
		int cnt; cin >> cnt;
		while (cnt--) {
			int cur; cin >> cur;
			st[i].insert(cur);
		}
	} 
	
	int q; cin >> q;
	while (q--)
	{
		int a, b; cin >> a >> b;
		unsigned dif = set_intersection(st[a].begin(), st[a].end(), 
										st[b].begin(), st[b].end(), 
										uni.begin()) - uni.begin();
		unsigned tot = set_union(st[a].begin(), st[a].end(), st[b].begin(), st[b].end(), uni.begin()) - uni.begin();
		double rate = double(dif)/tot;
		printf("%.2f%%\n", rate*100);
	}
}
