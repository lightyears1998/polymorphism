#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int maxN = 101000;

LL eureka[maxN];
vector<int> son[maxN];

int n;
double z, r;
double tot;

void walk(int x = 0, double rate = 1)
{
	if (eureka[x]) {
		tot += z*rate*eureka[x];
	}
	for (unsigned i=0; i<son[x].size(); ++i) {
		walk(son[x][i], rate*r);
	} 
}

int main()
{
	cin >> n >> z >> r;
	r = 1-r/100;
	
	for (int i=0; i<n; ++i) {
		int k; cin >> k;
		if (k == 0) {
			cin >> eureka[i];
			continue;
		} 
		while (k--) {
			int u; cin >> u;
			son[i].push_back(u);
		} 
	}
	
	walk();
	cout << LL(tot) << endl;
}
