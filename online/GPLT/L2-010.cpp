#include <bits/stdc++.h>
using namespace std;

const int maxN = 110;

int fa[maxN];
bool hate[maxN][maxN];

void init(int n) 
{
	iota(fa, fa+maxN, 0);
} 

int find(int x)
{
	return fa[x]==x ? fa[x] : fa[x] = find(fa[x]);
}

void merge(int a, int b)
{
	a = find(a), b = find(b);
	fa[a] = b;
}

bool isfriend(int a, int b)
{
	return find(a) == find(b);
}

int main()
{
	int n, m, k; cin >> n >> m >> k;
	
	init(n);
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		if (c == 1) merge(a, b);
		else hate[a][b] = hate[b][a] = true;
	}
	
	while (k--) {
		int a, b; cin >> a >> b;
		bool hateship = hate[a][b];
		bool friendship = isfriend(a, b);
		if (!hateship && friendship) {
			cout << "No problem" << endl;
		}
		else if (!hateship && !friendship) {
			cout << "OK" << endl;
		}
		else if (friendship && hateship) {
			cout << "OK but..." << endl;
		}
		else {
			cout << "No way" << endl;
		}
	}
}
