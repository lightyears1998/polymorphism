#include <bits/stdc++.h>
using namespace std;

const int maxN = 200000;

int peo[maxN];

int main()
{
	int n; cin >> n;
	while (n--) {
		int k; cin >> k;
		if (k == 1) {
			int q; scanf("%d", &q); 
			continue; 
		} 
		while (k--) {
			int q; scanf("%d", &q);
			peo[q]++;
		}
	}
	
	int m; cin >> m;
	bool outed = false;
	while (m--) {
		int q; cin >> q;
		if (!peo[q]) {
			if (outed) cout << ' ';
			peo[q] = 1;
			printf("%05d", q), outed = true;
		}
	}
	if (!outed) cout << "No one is handsome" << endl;
}
