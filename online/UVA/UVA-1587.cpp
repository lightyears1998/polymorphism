#include <bits/stdc++.h>
using namespace std;

// LeaderBoard
// https://vjudge.net/solution/9839273
// 维持长方形边长成对的性质并排序

pair<int, int> tri[6];

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif

	while (cin >> tri[0].first >> tri[0].second)
	{
		for (int i = 0; i < 6; ++i)
		{
			if (i)
				cin >> tri[i].first >> tri[i].second;
			if (tri[i].first > tri[i].second)
				swap(tri[i].first, tri[i].second);
		}
		sort(tri, tri + 6);

		bool ok = (tri[0] == tri[1] && tri[2] == tri[3] && tri[4] == tri[5]);
		if (ok)
			ok = (tri[0].first==tri[2].first && tri[0].second==tri[4].first && tri[2].second==tri[4].second);
		cout << (ok ? "POSSIBLE" : "IMPOSSIBLE") << endl;
	}
}
