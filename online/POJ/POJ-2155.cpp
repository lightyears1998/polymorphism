#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

const int maxN = 1010;

int leaf[maxN];
bool node[maxN<<2][maxN<<2];

#define ls (rt<<1)
#define rs ((rt<<1)|1)
void build(int rt, int l, int r)
{
	if (l == r) {
		leaf[l] = rt; return;
	}
	else {
		int mid = (l+r)/2;
		build(ls, l, mid);
		build(rs, mid+1, r);
	}
}

vector<int> key[2];
void locate(int rt, int l, int r, int layer, int p, int q)
{
	if (p<=l&&r<=q) {
		key[layer].push_back(rt);
	}
	else {
		int mid = (l+r)/2;
		if (p<=mid) locate(ls, l, mid, layer, p, min(q, mid));
		if (q>=mid+1) locate(rs, mid+1, r, layer, max(mid+1, p), q);
	}
}

void change(int x1, int y1, int x2, int y2)
{
	locate(1, 1, maxN, 0, x1, x2);
	locate(1, 1, maxN, 1, y1, y2);
	for (unsigned i = 0; i < key[0].size(); ++i)
		for (unsigned j = 0; j < key[1].size(); ++j)
			node[key[0][i]][key[1][j]] = !node[key[0][i]][key[1][j]];
	key[0].clear(); key[1].clear();
}

int query(int x, int y)
{
	int ans = 0;
	for (int i = leaf[x]; i; i>>=1)
		for (int j = leaf[y]; j; j>>=1)
			ans += node[i][j];
	return ans;
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	
	build(1, 1, maxN);
	
	int x; scanf("%d", &x);
	while (x--) 
	{
		memset(node, 0, sizeof(node));
		
		int n, t; scanf("%d%d", &n, &t);
		while (t--)
		{
			char ch; scanf(" %c", &ch);
			if (ch == 'C')
			{
				int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				change(x1, y1, x2, y2);
			}
			if (ch == 'Q')
			{
				int x, y; scanf("%d%d", &x, &y);
				puts(query(x, y)&1 ? "1" : "0");
			}
		}
		if (x) putchar('\n');
	}
}
