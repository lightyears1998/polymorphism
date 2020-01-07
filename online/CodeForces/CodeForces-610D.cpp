#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int maxN = 200002;

struct edge
{
	int x1, x2, y, type;
	bool operator <(const edge& b) const
	{
		return y < b.y;
	}
} e[maxN];

int h[maxN];
int len[maxN<<2], cover[maxN<<2];

#define ls (rt<<1)
#define rs ((rt<<1)|1)
void pushup(int rt, int l, int r)
{
	if (cover[rt]>0) len[rt] = h[r]-h[l];
	else 
	{
		if (l+1!=r) len[rt] = len[ls] + len[rs];
		else len[rt] = 0;
	}
}

void update(int rt, int l, int r, int p, int q, int v)
{
	if (p<=l&&r<=q) cover[rt] += v;
	else
	{
		int mid = (l+r)/2;
		if (p<mid) update(ls, l, mid, p, min(mid, q), v);
		if (q>mid) update(rs, mid, r, max(mid, p), q, v);
	}
	pushup(rt, l, r);
}

int main()
{
	int n; scanf("%d", &n);
	
	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if (x1>x2||y1>y2) swap(x1, x2), swap(y1, y2);
		--x1, --y1;
		e[res] = {x1, x2, y1, 1}; h[res++] = x1;
		e[res] = {x1, x2, y2,-1}; h[res++] = x2;
	}
	sort(h, h+res); res = unique(h, h+res)-h;
	sort(e, e+2*n);
	
	LL ans = 0;
	for (int i = 0; i < 2*n-1; ++i)
	{
		int p = lower_bound(h, h+res, e[i].x1)-h;
		int q = lower_bound(h, h+res, e[i].x2)-h;
		update(1, 0, res-1, p, q, e[i].type);
		ans += (LL)len[1]*(e[i+1].y-e[i].y);
	}
	printf("%lld\n", ans);
} 
