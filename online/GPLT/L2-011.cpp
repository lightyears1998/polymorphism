#include <bits/stdc++.h>
using namespace std;

int in[32], pre[32];
vector<int> tree[32];

void build(int root, int bgn, int end, int idx)
{
	if (bgn > end) return;
	int privot = find(in+bgn, in+end+1, pre[root])-in;
	tree[idx].push_back(pre[root]);
	build(root+1, bgn, privot-1, idx+1);
	build(root+privot-bgn+1, privot+1, end, idx+1);
}

int main()
{
	int n; cin >> n;
	for (int i=0; i<n; ++i) 
		cin >> in[i];
	for (int i=0; i<n; ++i)
		cin >> pre[i];
	build(0, 0, n-1, 0);
	
	cout << tree[0][0];
	for (int i=1; i<32; ++i) {
		reverse(tree[i].begin(), tree[i].end());
		for (int q : tree[i]) {
			cout << ' ' << q;
		}
	}
	cout << endl;
}
