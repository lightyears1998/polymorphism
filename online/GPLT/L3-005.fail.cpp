#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int maxN = 10100;

struct rating
{
	int idx;
	LL shortest, total;
	
	bool operator <(const rating &r) const {
		if (shortest != r.shortest) return shortest < r.shortest;
		if (total != total) return total > r.total;
		return idx > r.idx;
	}
};

int n, m, k, furthest; 
priority_queue<rating> ranking;
vector<int> son[maxN];
LL dis[maxN][maxN];

// It is more convenient to use stoi()
int read() {
	char ch; scanf(" %c", &ch);
	
	if (ch == 'G') return n+read();
	
	int num = ch-'0';
	while (scanf("%c", &ch), !(ch==' '||ch=='\n')) {
		num = num*10+ch-'0';
	}
	return num;
}

void walk(int root, LL distance, LL &total, LL &shortest, int fa = 0)
{
	if (!~total) return total;
	for (unsigned i=0; i<son[root].size(); ++i) {
		// Wrong method. G
		// It is not something about the walk of tree
	}
}

int main()
{
	cin >> n >> m >> k >> furthest;
	
	while (k--) 
	{
		int p1 = read(), p2 = read();
		scanf("%lld", &dis[p1][p2]);
		dis[p2][p1] = dis[p1][p2];
		son[p1].push_back(p2);
		son[p2].push_back(p1);
	}
	
	for (int i=n+1; i<=n+m; ++i) {
		LL shortest = 0, total = 0;
		walk(i, 0, total, shortest);
		if (!~total) continue;
		ranking.push({i, shortest, total});
	}
	
	if (ranking.size()) {
		cout << 'G' << ranking.top().idx-n << endl;
		printf("%.1f %.1f\n", ranking.top().shortest, (double)ranking.top().total/n);
	}
	else cout << "No Solution" << endl;
}
