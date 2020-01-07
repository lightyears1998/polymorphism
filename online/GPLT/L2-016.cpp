#include <bits/stdc++.h>
using namespace std;

const int maxN = 100100;

struct People
{
	int id;
	int fid, mid;
	char sex;
} node[maxN];

void search(int id, int gen, set<int> &parent)
{
	if (!gen || !~id) return;
	if (~node[id].fid) parent.insert(node[id].fid);
	if (~node[id].mid) parent.insert(node[id].mid);
	search(node[id].fid, gen-1, parent);
	search(node[id].mid, gen-1, parent);
}

int main()
{
	memset(node, -1, sizeof(node));
	
	int n; cin >> n;
	while (n--)
	{
		int id; cin >> id;
		People &p = node[id]; p.id = id;
		cin >> p.sex >> p.fid >> p.mid;
		if (~p.fid) node[p.fid].sex = 'M';
		if (~p.mid) node[p.mid].sex = 'F';
	}
	
	int m; cin >> m;
	while (m--)
	{
		int a, b; cin >> a >> b;
		if (node[a].sex == node[b].sex) {
			cout << "Never Mind" << endl;
			continue;
		}
		
		set<int> ap, bp; vector<int> rslt;
		search(a, 4, ap); search(b, 4, bp);
		set_intersection(ap.begin(), ap.end(), bp.begin(), bp.end(), back_inserter(rslt));
		cout << (rslt.size() ? "No" : "Yes") << endl;
	}
}
