#include <bits/stdc++.h>
using namespace std;

// 打表是不可能完成的，后期的表都是INF级别，不可能通过diff来判定
// 另外输入要分成两部分进行

long double rslt[10][31];

int main()
{
	long double mtot = 0, mbase = 1;
	for (int m = 0; m <=9; ++m)
	{
		mbase /= 2, mtot += mbase;
		long double etot = 0, ebase = 1;
		for (int e = 1; e <= 30; ++e)
		{
			etot += ebase, ebase *= 2;
			rslt[m][e] = mtot * pow(2, etot);
		}
	}

	long double n;
	while (cin >> n && n != 0)
	{
		int cm = 1, ce = 1;
		long double diff = numeric_limits<long double>::infinity();
		for (int m = 0; m <= 9; ++m)
		{
			for (int e = 1; e <= 30; ++e)
			{
				if (abs(rslt[m][e] - n) < diff) {
					diff = abs(rslt[m][e] - n);
					cm = m, ce = e;
				}
			}
		}
		cout << cm << ' ' << ce << endl;
	}
}
