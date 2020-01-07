#include <bits/stdc++.h>
using namespace std;

const int maxN = 1001001;

int tot, cnt[maxN];
map<char, int> mp[maxN]; 

int init() {
    return ++tot;
}

double dfs(int pos)
{
    double ans = 0;
    for (auto it=mp[pos].begin(); it!=mp[pos].end(); ++it) {
    	int nxt = it->second;
    	ans += (0.5*cnt[nxt]*(cnt[nxt]-1));
		ans += dfs(nxt);
    }
    return ans;
}

signed main() {	
    int n; cin >> n;
    for (int i=0; i<n; ++i) {
        string s; cin >> s;
        
        int cur = 0;
        for (char &ch : s) {
            if (!mp[cur][ch]) {
                mp[cur][ch] = init();
            }
            cur = mp[cur][ch];
            ++cnt[cur];
        }
    } 
    
    double ans = dfs(0);
    
    cout.flags(cout.fixed);
    cout.precision(10);
    cout << ans/(0.5*n*(n-1)) << endl;
}