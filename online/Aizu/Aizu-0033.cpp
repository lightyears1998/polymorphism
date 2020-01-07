#include <bits/stdc++.h>
using namespace std;

bool ok;
int ball[10];
stack<int> a, b;

void dfs(int i)
{
	if (ok) return;
	if (i == 10) {
		ok = true; return;
	}
	if (a.empty() || (!a.empty() && ball[i] > a.top())) {
		a.push(ball[i]); dfs(i+1); a.pop();
	}
	if (b.empty() || (!b.empty() && ball[i] > b.top())) {
		b.push(ball[i]); dfs(i+1); b.pop();
	}
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		ok = false;
		for (int i = 0; i < 10; ++i) scanf("%d", &ball[i]);
		a.push(ball[0]); dfs(1); a.pop();
		puts(ok ? "YES" : "NO");
	}
}

