#include <bits/stdc++.h>
using namespace std;

const int INF  = 0x3F3F3F3F; 
const int maxN = 50050;

int mx;
int tail[maxN] {-INF};

int main()
{
	int n; scanf("%d", &n);
	while (n--)
	{
		int elem; scanf("%d", &elem);
		int pos = upper_bound(tail, tail+mx+1, elem)-tail;
		tail[pos] = elem; 
		mx = max(mx, pos);
	}
	printf("%d\n", mx);
}
