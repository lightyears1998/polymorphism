#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> node[32];
int post[32], in[32];

// Positioning in post order requires root, 
// while in Inorder requirces privot, bgn and end. 

void build(int root, int bgn, int end, int idx)
{
	if (bgn > end) return;
	int privot = find(in+bgn, in+end+1, post[root])-in;
	node[idx].push_back(post[root]);
	build(root-(end-privot)-1, bgn, privot-1, idx+1);
	build(root-1, privot+1, end, idx+1);
}

void walk(int tot)
{
	cout << node[0][0];
	for (int i=1; i<=tot; ++i) {
		if (node[i].size()) {
			for (int j : node[i]) cout << ' ' << j;
		}
	}
	cout << endl;
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> post[i];	
	}
	for (int i=0; i<n; ++i) {
		cin >> in[i];
	}
	build(n-1, 0, n-1, 0);
	walk(n);
}
