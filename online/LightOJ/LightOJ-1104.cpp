#include <bits/stdc++.h>
using namespace std;

int get(int d)
{
	int n = 0;
	
	long double tot = 1, chs = 1;
	while (true)
	{
		if (chs/tot <= 0.5) return n;
		++n;
		tot *= d;
		chs *= d-n+1;
	}
}

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int d; cin >> d;
		cout << "Case " << i << ": " << get(d) - 1 << endl;
	}
} 
