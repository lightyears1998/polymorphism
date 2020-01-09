// 51Nod 2006 - 飞行员配对

#include <bits/stdc++.h>
using namespace std;

const int maxN = 1010;

int m, n;
bool line[maxN][maxN];
bool used[maxN];
int match[maxN];

bool find(int x)
{
	for (int i = 1; i<= n; ++i) {
		if (!used[i] && line[x][i]) {
			used[i] = true;
			if (!match[i] || find(match[i])) {
				match[i] = x;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	cin >> m >> n;
	while (true) {
		int i, j; cin >> i >> j;
		if (~i && ~j) {
			j -= m;
			line[i][j] = true;
		}
		else break;
	}
	
	int all = 0;
	for (int i=1; i<=m; ++i) {
		memset(used, 0, sizeof(used));
		if (find(i)) ++all;
	}
	if (all) 
		cout << all << endl;
	else cout << "No Solution!" << endl;
}