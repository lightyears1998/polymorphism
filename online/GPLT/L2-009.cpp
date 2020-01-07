#include <bits/stdc++.h>
using namespace std;

struct people
{
	int id, cnt, money;
	bool operator <(const people &p) const
	{
		if (money != p.money) return money > p.money;
		if (cnt != p.cnt) return cnt > p.cnt;
		return id < p.id;
	}
} node[10100];

int main()
{
	int n; cin >> n;
	for (int i=1; i<=n; ++i)
	{
		node[i].id = i;
		
		int k; cin >> k;
		while (k--) {
			int id, opy;
			cin >> id >> opy;
			node[id].cnt++;
			node[id].money += opy;
			node[i].money -= opy;
		}
	}
	
	sort(node+1, node+1+n);
	for (int i=1; i<=n; ++i) {
		printf("%d %.2f\n", node[i].id, double(node[i].money)/100);
	}
}
