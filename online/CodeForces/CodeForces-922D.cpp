#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL noise(string s)
{
	LL ans = 0, cnt = 0;
	for (char c : s)
	{
		if (c == 's') ++cnt;
		else ans += cnt;
	}
	return ans;
}

bool cmp(string &a, string &b)
{
	return noise(a+b) > noise(b+a);
}

string s[100500], final;

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> s[i];
	sort(s, s+n, cmp);
	for (int i = 0; i < n; ++i) final += s[i];
	cout << noise(final) << endl;
}

