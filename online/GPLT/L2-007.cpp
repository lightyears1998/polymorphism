#include <bits/stdc++.h>
using namespace std;

const int maxN = 10050;

// 思路是设法维护一个动态集合，然而动态的东西都难于调试，
// 还有更清晰的写法
// https://www.liuchuo.net/archives/2198 

int fmcnt;
struct family 
{
	int id, mcnt, hcnt;
	double harea, avg;
	bool operator <(const family &f) const
	{
		if (avg != f.avg) return avg > f.avg;
		return id < f.id;
	}
} fm[maxN];

int pre[maxN];

void init()
{
	iota(pre, pre+maxN, 0);
}

void init(int x)
{
	if (!fm[x].id) {
		++fmcnt;
		fm[x].id = x;
		fm[x].mcnt = 1;
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
	else pre[b] = a, --fmcnt;
	fm[a].id = min(fm[a].id, fm[b].id);
	fm[a].mcnt += fm[b].mcnt;
	fm[a].hcnt += fm[b].hcnt;
	fm[a].harea += fm[b].harea;
	fm[b].mcnt = 0;
}

void update()
{
	for (int i=0; i<maxN; ++i) {
		if (fm[i].mcnt) fm[i].avg = fm[i].harea / fm[i].mcnt;
	}
}

int main()
{
	init();
	
	int n; cin >> n;
	while (n--)
	{
		int id; cin >> id; init(id);
		int father, mother; cin >> father >> mother;
		if (~father) init(father), merge(id, father);
		if (~mother) init(mother), merge(id, mother);
		int kid; cin >> kid;
		while (kid--) {
			int k; cin >> k;
			init(k), merge(id, k);
		}
		id = find(id);
		int hcnt; double harea; cin >> hcnt >> harea;
		fm[id].hcnt += hcnt;
		fm[id].harea += harea; 
	}
	
	update();
	sort(fm, fm+maxN);
	
	cout << fmcnt << endl;
	for (int i=0; i<maxN; ++i) {
		if (fm[i].id>=0 && fm[i].mcnt) {
			printf("%04d %d %.3f %.3f\n", fm[i].id, fm[i].mcnt, double(fm[i].hcnt)/fm[i].mcnt, fm[i].avg);
		} 
	}
}
