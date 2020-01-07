#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	char ch; cin >> ch;
	
	int tot = 1, line = 1, height = 1;
	while (n >= tot+line*2+4) {
		line += 2;
		tot += line*2;
		height += 2;
	}
	
	int width = line, dir = -2;
	for (int i=1; i<=height; ++i) {
		int space = (width-line)/2;
		while (space--) cout << ' ';
		for (int j=1; j<=line; ++j)
			cout << ch;
		line += dir;
		if (line==-1) dir = 2, line = 3;
		cout << endl;
	}
	cout << n-tot << endl;
}
