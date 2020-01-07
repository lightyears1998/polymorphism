#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int a, b, c, d; cin >> a >> b >> c >> d;
		if (b-a == c-b && b-a == d-c) 
			printf("%d %d %d %d %d\n", a, b, c, d, d+d-c);
		else
			printf("%d %d %d %d %d\n", a, b, c, d, d/c*d);
	}
}
