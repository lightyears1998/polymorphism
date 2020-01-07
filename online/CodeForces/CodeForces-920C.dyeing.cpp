#include <bits/stdc++.h>
using namespace std;

// 染色法，效率与计数法相当

const int maxN = 200200;

int num[maxN], dye[maxN];

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> num[i];
		dye[i] = i;
	}
	string s; cin >> s;
	for (int i = 1; i < n; ++i)
	{
		if (s[i-1] == '1') dye[i+1] = dye[i];
	}

	bool flag = true;
	for (int i = 1; i <= n; ++i)
	{
		if (dye[i] != dye[num[i]]) flag = false;
	}
	cout << (flag ? "YES" : "NO") << endl;
}
