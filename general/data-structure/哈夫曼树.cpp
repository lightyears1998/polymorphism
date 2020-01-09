#include <bits/stdc++.h>
using namespace std;
using LL = long long;

priority_queue<LL, vector<LL>, greater<LL>> que;

LL huffman()
{
	LL ans = 0;
	while (que.size() != 1)
	{
		LL a = que.top(); que.pop();
		LL b = que.top(); que.pop();
		ans += a + b, que.push(a + b);
	}
	return ans;
}

int main()
{
	int n; cin >> n;
	while (n--)
	{
		LL cur; cin >> cur;
		que.push(cur);
	}
	cout << huffman() << endl;
}

