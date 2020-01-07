#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	
	double sum = 0;
	for (int i=1; i<=n; ++i) sum += log10(i);
	cout << (int)sum+1 << endl;
}
