#include <bits/stdc++.h>
using namespace std;

// Reference - https://www.liuchuo.net/archives/2155

unsigned n;
vector<int> pre, post;
bool isMirrored;

void getPost(int root, int tail)
{
	if (root > tail) return;
	int i = root+1, j = tail;
	if (!isMirrored) {
		while (i <= tail && pre[i]<pre[root]) ++i;
		while (j > root && pre[j]>=pre[root]) --j;
	}
	else {
		while (i <= tail && pre[i]>=pre[root]) ++i;
		while (j > root && pre[j]<pre[root]) --j;
	}
	if (i-j != 1) return;
	getPost(root+1, j);
	getPost(i, tail);
	post.push_back(pre[root]);
}

bool judge()
{
	if (post.size() == n) {
		cout << "YES" << endl;
		for (unsigned i=0; i<post.size(); ++i) {
			if (i) cout << ' ';
			cout << post[i];
		}
		return true;
	}
	return false;
}

int main()
{
	cin >> n;
	pre.resize(n);
	
	for (unsigned i=0; i<n; ++i) cin >> pre[i];
	
	getPost(0, n-1);
	if (!judge()) 
	{
		isMirrored = true;
		post.clear();
		getPost(0, n-1);
		if (!judge())
			cout << "NO" << endl;
	} 
} 
