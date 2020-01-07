#include <bits/stdc++.h>
using namespace std;

const int maxN = 10050;

struct node
{
	int id, people, house; 
	double area, avg;
	bool operator <(const node &t) const
	{
		if (avg != t.avg) return avg > t.avg;
		return id < t.id;
	}
} fm[maxN];

bool vis[maxN], rooted[maxN];
int pre[maxN];

void init()
{
	for (int i=0; i<maxN; ++i) {
		pre[i] = i;
		fm[i].id = i;
		fm[i].people = 1;
	}
}

void update() {
	for (node &n : fm) {
		if (vis[n.id]) n.avg = n.area / n.people;
	}
}

int find(int x)
{
	return pre[x]==x ? pre[x] : pre[x]=find(pre[x]);
}

void merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a == b) return;
	if (a > b) pre[a] = b; 
	else pre[b] = a;
}

int main()
{
	init();
	
	int n; cin >> n;
	while (n--)
	{
		int id, fid, mid; cin >> id >> fid >> mid;
		vis[id] = true;
		if (~fid) vis[fid] = true, merge(id, fid);
		if (~mid) vis[mid] = true, merge(id, mid);
		int kid; cin >> kid;
		while (kid--) {
			int k; cin >> k;
			vis[k] = true; merge(id, k);
		}
		cin >> fm[id].house >> fm[id].area;
	}
	
	int cnt = 0;
	for (int i=0; i<maxN; ++i) {
		if (vis[i]) {
			int rt = find(i);
			if (rt == i) {
				++cnt; rooted[fm[i].id] = true;
				continue;
			}
			fm[rt].people++;
			fm[rt].house += fm[i].house;
			fm[rt].area += fm[i].area;
		}
	}
	
	update(), sort(fm, fm+maxN);
	cout << cnt << endl;
	for (int i=0; i<maxN; ++i) if (rooted[fm[i].id]) {
		printf("%04d %d %.3f %.3f\n", fm[i].id, fm[i].people, double(fm[i].house)/fm[i].people, fm[i].avg);
	}
} 
