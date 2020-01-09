#include <bits/stdc++.h>
using namespace std;

int egcd(int a, int b, int &x, int &y)
{
	if (b == 0) {
		x = 1, y = 0;
		return a;
	} else {
		int r = egcd(b, a%b, y, x);
		y -= (a/b)*x;
		return r;
	}
}

int main()
{
	int m, n;
	while (cin >> m >> n && m) {
		int a, b; 
		egcd(m, n, a, b);
		a%=n; a+=n; a%=n;
		cout << a << endl;
	}
} 
