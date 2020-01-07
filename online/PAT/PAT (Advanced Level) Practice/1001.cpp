// 1001 A + B Format

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int32_t main()
{
	int a, b; cin >> a >> b;
	string sum = to_string(a + b);

	string fmt;
	for (int i = sum.length()-1, cnt = 0; i >= 0; --i)
	{
		if (sum[i] == '-') {
			fmt += "-"; break;
		}
		if (cnt == 3) {
			fmt += ",", cnt = 0;
		}
		fmt += sum[i], ++cnt;
	}
	reverse(fmt.begin(), fmt.end());
	cout << fmt << endl;
}
