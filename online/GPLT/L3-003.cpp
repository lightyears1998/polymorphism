#include <bits/stdc++.h>
using namespace std;

const int maxN = 1024;

int pre[maxN];
int size[maxN];
bool recorded[maxN];

int find(int x) 
{
	return pre[x] == x ? pre[x] : pre[x] = find(pre[x]);
}

void merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a == b) return;
	pre[b] = a; size[a] += size[b];
}

int main()
{
	for (int i=0; i<maxN; ++i)
		pre[i] = i;
	
	int n; scanf("%d", &n);
	
	vector<int> vec;
	while (n--) {
		vec.clear();
		int k; scanf("%d:", &k);
		while (k--) {
			int num; scanf("%d", &num);
			vec.push_back(num);	
		}
		for (unsigned i=0; i<vec.size(); ++i) merge(vec[0], vec[i]);
		size[find(vec[0])]++;
	}
	
	vec.clear();
	for (int i=0; i<maxN; ++i) {
		int k = find(i);
		if (recorded[k]) continue;
		if (size[k]) vec.push_back(size[k]);
		recorded[k] = true;
	}
	
	sort(vec.begin(), vec.end(), greater<int>());
	printf("%zd\n%d", vec.size(), vec[0]);
	for (unsigned i=1; i<vec.size(); ++i) printf(" %d", vec[i]);
	printf("\n");
}
