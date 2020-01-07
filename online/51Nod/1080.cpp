#include <bits/stdc++.h>
using namespace std;
using LL = long long;

set<LL> st;
unordered_map<LL, LL> mp;

int main()
{
	LL n; cin >> n;
	
	for (LL i=1; i*i<=n; ++i)
		st.insert(i*i), mp[i*i]=i;
	
	int ans = 0;
	for (LL i=0; i*i<=n; ++i) {
		LL j=n-i*i;
		if (st.find(j) != st.end()) {
			if (i <= mp[j])
				cout << i << ' ' << mp[j] << endl, ++ans;
			else break;
		}
	}
	if (!ans) cout << "No Solution" << endl;
}
 
