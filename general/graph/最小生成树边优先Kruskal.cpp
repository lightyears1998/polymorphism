#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct edge
{
	int a, b; LL dis;
	bool operator < (const edge oth) const
	{
		return dis < oth.dis;
	}
} e[50050];

int n, m;
int father[1010];

int find(int a)
{
	return father[a] == a ? a : father[a] = find(father[a]);
}

bool query(int a, int b)
{
	return find(a) == find(b);
}

void merge(int a, int b)
{
	father[find(a)] = find(b);
}

LL kruskal()
{
	LL ans = 0;
	sort(e, e+m);
	for (int i = 0; i < m; ++i)
	{
		if (query(e[i].a, e[i].b)) continue;
		ans += e[i].dis, merge(e[i].a, e[i].b);
	}
	return ans;
}

int main()
{
	cin >> n >> m; 
	for (int i = 1; i <= n; ++i)
	{
		father[i] = i;
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> e[i].a >> e[i].b >> e[i].dis;
	}
	cout << kruskal() << endl;
} 

