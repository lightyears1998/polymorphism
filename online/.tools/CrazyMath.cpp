/**
 * A tool for practicing oral arithmetics.
 */

#include <bits/stdc++.h>
using namespace std;

int ac, wa;
vector<int> num {11};

clock_t tot;

int main()
{
	while (true)
	{
		int i = rand() % num.size();
		int p = rand() % num[i];

		cout << num[i] << '-' << p << '?' << endl;
		clock_t bgn = clock();

		int q; cin >> q;
		tot += clock() - bgn;

		if (q == num[i]-p) ++ac, cout << "AC" << endl;
		else
		{
			++wa, cout << "WA" << endl;
			cout << num[i] << '-' << p << '=' << num[i]-p << endl;
		}

		if ((ac+wa) % 10 == 0) {
			cout << "AC: " << ac << " WA: " << wa << endl;
			cout << "Time: " << tot / CLOCKS_PER_SEC << endl;
		}
	}
}
