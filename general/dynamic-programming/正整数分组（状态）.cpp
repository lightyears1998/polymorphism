#include <bits/stdc++.h>
using namespace std;

const int maxN = 101;
const int maxM = 10001;

int num[maxN];
bool status[maxN][maxM];

int main()
{
	status[0][0] = true;
	
	int n; scanf("%d", &n);
	for (int i=1; i<=n; ++i) {
		scanf("%d", &num[i]);
	}
	
	for (int i=1; i<=n; ++i) {
		for (int j=0; j<maxM; ++j) {
			status[i][j] = status[i-1][abs(j-num[i])] || (j+num[i] < maxM && status[i-1][j+num[i]]);
		}
	}
	
	for (int i=0; i<maxM; ++i) {
		if (status[n][i]) {
			printf("%d\n", i);
			break;
		}
	}
}
