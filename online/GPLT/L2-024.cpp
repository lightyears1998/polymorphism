#include <bits/stdc++.h>
using namespace std;

const int maxN = 10100;

int cnt;
int pre[maxN];
set<int> peo;

void init()
{
	iota(pre, pre+maxN, 0);
}

int find(int x)
{
	return pre[x]==x ? pre[x] : pre[x] = find(pre[x]);
}

void merge(int a, int b) 
{	
	a = find(a), b = find(b);
	if (a == b) return;
	pre[a] = b, --cnt;
}

bool query(int a, int b)
{
	return find(a) == find(b);
}

int main()
{
	init();
	
	int n; cin >> n;
	while (n--) {
		int k, leader; cin >> k >> leader;
		peo.insert(leader);
		while (--k) {
			int member; cin >> member;
			merge(leader, member); 
			peo.insert(member);
		}
	}
	
	cout << peo.size() << ' ' << cnt+peo.size() << endl;
	int q; cin >> q;
	while (q--) {
		int a, b; cin >> a >> b;
		cout << (query(a, b) ? "Y" : "N") << endl;
	}
} 
