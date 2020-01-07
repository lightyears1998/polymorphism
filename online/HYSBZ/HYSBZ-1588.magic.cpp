#include <bits/stdc++.h>
using namespace std;

// Fail to test time efficiency without splaying the tree
// beacaue splay is needed when try to find prev node or next node

const int maxN = 100100;
const int INF = 0x3F3F3F3F;

int tot, root;
int val[maxN], ch[maxN][2], pre[maxN];

void init()
{
	tot = 0;
	memset(val, 0, sizeof(val));
	memset(ch, 0, sizeof(ch));
	memset(pre, 0, sizeof(pre));
	val[0] = INF;
}

int assign(int &r, int father, int value)
{
	r = ++tot;
	pre[r] = father, val[r] = value;
	return tot;
}

void rotate(int x, int kind)
{
	int y = pre[x];
	ch[y][!kind] = ch[x][kind];
	pre[ch[x][kind]] = y;
	if (pre[y])
		ch[pre[y]][ch[pre[y]][1] == y] = x;
	pre[x] = pre[y];
	pre[y] = x;
	ch[x][kind] = y;
}

void splay(int x, int goal)
{
	while (pre[x] != goal)
	{
		if (pre[pre[x]] == goal) 
			rotate(x, ch[pre[x]][0] == x);
		else
		{
			int y = pre[x];
			int kind = ch[pre[y]][0] == y;
			if (ch[y][kind] == x) {
				rotate(x, !kind);
				rotate(x, kind);
			}
			else {
				rotate(y, kind);
				rotate(x, kind);
			}
		} 
	}
	if (goal == 0) root = x;
}

int insert(int value)
{
	int r = root;
	while (ch[r][val[r]<value])
		r = ch[r][val[r]<value];
	int idx = assign(ch[r][val[r]<value], r, value);
	// splay(idx, 0);
	return idx;
}

int prev(int x)
{
	int nxt = ch[x][0];
	while (ch[nxt][1])
		nxt = ch[nxt][1];
	return min(abs(val[x]-val[nxt]), abs(val[x]-val[pre[x]]));
}

int next(int x)
{
	int nxt = ch[x][1];
	while (ch[nxt][0])
		nxt = ch[nxt][0];
	return min(abs(val[x]-val[nxt]), abs(val[x]-val[pre[x]]));
}

void dump(int x)
{
	if (ch[x][0]) dump(ch[x][0]);
	cout << val[x] << ' ';
	if (ch[x][1]) dump(ch[x][1]);
}

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		init();
		int ans = 0;
		
		int today; scanf("%d", &today);
		assign(root, 0, today); ans += today;
		while (--n)
		{
			scanf("%d", &today);
			int idx = insert(today);
			
			int a = prev(idx), b = next(idx);
			ans += min(a, b);
			dump(root); printf("-%d", ans); cout << endl;
		}
		printf("%d\n", ans);
	}
}
