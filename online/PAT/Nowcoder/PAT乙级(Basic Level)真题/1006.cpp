#include <iostream>
using namespace std;
using LL = long long;

LL GetPart(LL number, LL part)
{
	LL ret = 0;
	while (number)
	{
		if (number % 10 == part)
		{
			ret = ret*10 + part;
		}
		number /= 10;
	}
	return ret;
}

signed main()
{
	LL a, da, b, db; cin >> a >> da >> b >> db;
	cout << GetPart(a, da) + GetPart(b, db) << endl;
}
