#include <bits/stdc++.h>
using namespace std;

int n, k, m;
int p[25];

void go(int &pos, int dir, int step)
{
	while (step--)
	{
		do {
			pos = (pos+dir+n-1) % n+1;
		} while (p[pos] == 0);
	}
}

int main()
{
	while (scanf("%d%d%d", &n, &k, &m) == 3 && n)
	{
		iota(p+1, p+1+n, 1);
		
		int left = n;
		int p1 = 0, p2 = n+1;
		while (left)
		{
			go(p1, 1, k); go(p2, -1, m);
			printf("%3d", p[p1]), --left;
			if (p1 != p2) printf("%3d", p[p2]), --left;
			p[p1] = p[p2] = 0;
			if (left) printf(",");
		}
		printf("\n");
	}
}
