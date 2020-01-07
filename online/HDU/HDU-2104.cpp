#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) 
{
	return b==0? a : gcd(b, a%b);	
}

int main()
{
	int n, m; 
	while (scanf("%d%d", &n, &m) == 2 && ~n)
	{
		printf(gcd(n, m) == 1 ? "YES\n" : "POOR Haha\n");
	} 
}
