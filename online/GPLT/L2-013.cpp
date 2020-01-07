#include <bits/stdc++.h>
using namespace std;

const int maxN = 550;

int n, tot;
bool captured[maxN]; 
bool path[maxN][maxN];
bool mark[maxN];

void tag(int pos)
{
	mark[pos] = true;
	for (int i=0; i<n; ++i) {
		if (!captured[i] && path[pos][i] && !mark[i]) 
			tag(i);
	}
}

int check()
{
	int cnt = 0;
	memset(mark, 0, sizeof(mark));
	
	for (int i=0; i<n; ++i) {
		if (!captured[i] && !mark[i]) 
			tag(i), ++cnt;
	}
	return cnt;
}

int main()
{
	int m; cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		path[a][b] = path[b][a] = true;
	}
	tot = check();
	
	int k; cin >> k;
	while (k--) {
		int cap; cin >> cap;
		captured[cap] = true;
		int now = check();
		if (now <= tot) 
			printf("City %d is lost.\n", cap);
		else 
			printf("Red Alert: City %d is lost!\n", cap);
		tot = now;
	}
	if (!check()) cout << "Game Over." << endl;
}
