#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a, b;
	getline(cin, a); getline(cin, b);
	
	for (int i = 0; i < a.size(); ++i)
	{
		if (~b.find(a[i])) {
			a.replace(i, 1, "");
			--i;
		}
	} 
	cout << a << endl;
}
