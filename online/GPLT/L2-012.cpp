#include <bits/stdc++.h>
using namespace std;

int tot;
int node[1<<16];

void up(int pos) {
	int upper = pos>>1;
	if (upper && node[pos] < node[upper]) {
		swap(node[upper], node[pos]);
		up(upper);
	}
}

void insert(int x)
{
	node[++tot] = x;
	up(tot);
}

int main()
{
	node[0] = 0x3F3F3F3F;	
	int n, m; cin >> n >> m;
	
	while (n--) {
		int k; cin >> k;
		insert(k);
	}
	
	string s; getline(cin, s);
	while (m--) {
		getline(cin, s);
		stringstream cin(s);
		
		int x; cin >> x;
		string nxt; cin >> nxt;
		if (nxt == "is") {
			cin >> nxt;
			if (nxt == "the") {
				cin >> nxt;
				if (nxt == "root") {
					cout << (node[1] == x ? "T" : "F") << endl; 
				}
				else {
					cin >> nxt;
					int p; cin >> p;
					int pos = find(node+1, node+tot+1, p)-node;
					cout << (node[pos>>1] == x ? "T" : "F") << endl; 
				}
			}
			else {
				cin >> nxt >> nxt;
				int p; cin >> p;
				int pos = find(node+1, node+tot+1, x)-node;
				cout << (node[pos>>1] == p ? "T" : "F") << endl;
			}
		}
		if (nxt == "and") {
			int y; cin >> y;
			int pos = find(node+1, node+tot+1, x)-node;
			cout << (node[pos^1] == y? "T" : "F") << endl;
		}
	}
}
