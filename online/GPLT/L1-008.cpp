#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b; cin >> a >> b;
	
	int cnt = 0, sum = 0;
	for (int i=a; i<=b; ++i) {
		printf("%5d", i);
		sum += i;
		++cnt; if (cnt%5==0) putchar('\n');
	}
	if (cnt%5) putchar('\n');
	cout << "Sum = " << sum << endl;
}
