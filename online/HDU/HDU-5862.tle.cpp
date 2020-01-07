#include <bits/stdc++.h>
using namespace std;

// 朴素扫描线方法 - TLE
// 时间复杂度分析 O(n^2*log(n))

const int maxN = 100100;

struct edge
{
	int x1, x2, y, type; // 1-纵线入 2-横线 3-纵线出
	bool operator <(const edge b) const
	{
		if (y != b.y) return y < b.y;
		if (type != b.type) return type < b.type;
		return x1 < b.x1;
	}
} e[maxN<<1];

int h[maxN<<1];

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		int n; scanf("%d", &n);

		int ecnt = 0, hcnt = 0;
		for (int i=0; i<n; ++i)
		{
			int x1, y1, x2, y2;
			if (x1>x2 || y1>y2)  swap(x1, x2), swap(y1, y2);
			if (y1 == y2)
				e[ecnt++] = {x1, x2, y1, 2};
			else
				e[ecnt++] = {x1, x2, y1, 1}, e[ecnt++] = {x1, x2, y2, 3};
			h[hcnt++] = x1, h[hcnt++] = x2;
		}
		sort(e, e+ecnt);
		sort(h, h+hcnt); hcnt = unique(h, h+hcnt)-h;

		set<int> pt;
		int ans = 0;
		for (int i=0; i<ecnt; ++i)
		{
			if (e[i].type==1) pt.insert(lower_bound(h, h+hcnt, e[i].x1)-h);
			if (e[i].type==3) pt.erase(lower_bound(h, h+hcnt, e[i].x2)-h);
			if (e[i].type==2)
			{
				int p = lower_bound(h, h+hcnt, e[i].x1)-h;
				int q = lower_bound(h, h+hcnt, e[i].x2)-h;
				auto it = pt.lower_bound(p);
				while (it!=pt.end() && *it<=q) ++ans, ++it;
			}
		}
		printf("%d\n", ans);
	}
}
