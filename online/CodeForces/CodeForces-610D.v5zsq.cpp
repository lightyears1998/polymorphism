#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define ls (rt<<1)
#define rs ((rt<<1)|1)

// http://blog.csdn.net/v5zsq/article/details/70258228
// 线段数点 ==> 矩形的并

const int INF = 0x3F3F3F3F;
const int maxN = 200002;

int n;
int limit = maxN << 2;

struct edge
{
    int x1, x2, y, type;
    bool operator <(const edge&b) const
    {
        return y < b.y;
    }
} e[maxN];

int h[maxN];
LL len[maxN<<3], cover[maxN<<3];

void pushup(int rt, int l, int r)
{
    if (cover[rt]) len[rt] = h[r]-h[l];
    else
    {
        if (l==r) len[rt] = 0;
        else len[rt] = len[ls] + len[rs];
    }
    assert(rs < limit);
}

void update(int rt, int l, int r, int L, int R, int v)
{
	assert(rt < limit);
    if (l==r) return;
    if (L<=l&&R>=r) {
    	cover[rt] += v;
    	if (l+1!=r) pushup(rt, l, r);
	}
    else
    {
        int mid = (l+r)/2;
        if (mid>L) update(ls, l, mid, L, R, v);
        if (mid<R) update(rs, mid, r, L, R, v);
        pushup(rt, l, r);
    }
}

signed main()
{
	while (scanf("%d", &n) == 1)
	{
		memset(len, 0, sizeof(len));
		memset(cover, 0, sizeof(cover));

		int res = 0;
		for (int i=1; i<=n; ++i)
		{
			int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			if (x1>x2 || y1>y2) swap(x1, x2), swap(y1, y2);
			--x1, --y1;
			e[res] = {x1, x2, y1, 1}; h[res++] = x1;
			e[res] = {x1, x2, y2,-1}; h[res++] = x2;
		}
		sort(h, h+res); res = unique(h, h+res)-h;
		sort(e, e+2*n);

		LL ans = 0;
		for (int i=0; i<2*n-1; ++i)
		{
			int L = lower_bound(h, h+res, e[i].x1) - h;
			int R = lower_bound(h, h+res, e[i].x2) - h;
			update(1, 0, res-1, L, R, e[i].type);
			ans += (LL)len[1]*(e[i+1].y-e[i].y);
		}
		printf("%lld\n", ans);
	}
}
