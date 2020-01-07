#include <bits/stdc++.h>
using namespace std;

int main()
{
	int cp, og; cin >> cp >> og;
	switch (og) 
	{
		case 0: 
			cout << "NO" << endl; break;
		case 1: 
			cout << (cp == 0 ? "YES" : "NO") << endl; break;
		default: 
			cp -= og - 1; 
			cout << (cp >= 0 && cp % 2 == 0 ? "YES" : "NO") << endl;
	}
}

