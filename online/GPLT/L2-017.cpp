#include <bits/stdc++.h> 
using namespace std;

const int maxN = 100010;

int unit[maxN];

int main()
{
	int n; cin >> n;
	for (int i=0; i<n; ++i)
		cin >> unit[i];
	sort(unit, unit+n);
	
	int sum1 = accumulate(unit, unit+n/2, 0);
	int sum2 = accumulate(unit+n/2, unit+n, 0);
	
	cout << "Outgoing #: " << n/2+n%2 << endl;
	cout << "Introverted #: " << n/2 << endl;
	cout << "Diff = " << abs(sum1 - sum2) << endl;
} 
