#include <bits/stdc++.h>
using namespace std;

map<char, double> mass;

int main()
{
	cout.flags(cout.fixed); cout.precision(3);
	mass['C'] = 12.01, mass['H'] = 1.008;
	mass['O'] = 16.00, mass['N'] = 14.01;
 	
	int n; cin >> n;
	while (n--)
	{
		string s; cin >> s;
		char prev;
		double tot = 0; int cnt = 0;
		for (char cur : s)
		{
			if (isdigit(cur))
				cnt = cnt * 10 + cur - '0';
			else 
			{
				if (cnt)
					tot += mass[prev] * (cnt - 1), cnt = 0;
				tot += mass[cur], prev = cur;
			}
		}
		if (cnt)
			tot += mass[prev] * (cnt - 1), cnt = 0;	
		cout << tot << endl;
	} 
}
