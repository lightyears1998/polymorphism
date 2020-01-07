#include <bits/stdc++.h>
using namespace std;

const int maxN = 10100;

double pt[maxN];
double cur[maxN];

int main()
{
	int n, k, m; cin >> n >> k >> m;
	
	for (int i=0; i<n; ++i)
	{
		for (int j=0; j<k; ++j) {
			cin >> cur[j];
		}
		sort(cur, cur+k);
		pt[i] = double(accumulate(cur+1, cur+k-1, 0))/(k-2);
	}
	sort(pt, pt+n, greater<double>());
	
	printf("%.3f", pt[m-1]);
	for (int i=m-2; i>=0; --i) {
		printf(" %.3f", pt[i]);
	}
	putchar('\n');
}
