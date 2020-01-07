#include <bits/stdc++.h>
using namespace std;

int trail[100010];

int main()
{
	int n; scanf("%d", &n);
	
	unsigned bound = 0;
	while (n--) 
	{
		int k; scanf("%d", &k);
		unsigned pos = upper_bound(trail, trail+bound, k)-trail;
		trail[pos] = k;
		if (pos == bound) ++bound;
	}
	printf("%u\n", bound);
}
