#include <bits/stdc++.h>
using namespace std;

const int maxN = 1010;

string a, b; 
int dp[maxN][maxN];

void lcs()
{
	for (unsigned i=0; i<=a.size(); ++i) {
		for (unsigned j=0; j<=b.size(); ++j) {
			if (i==0||j==0) 
				dp[i][j] = 0;
			else {
				if (a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
				else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
}

void print()
{
	string ans;
	
	unsigned i = a.size(), j = b.size();
	while (i && j) {
		if (a[i-1] == b[j-1]) ans.push_back(a[i-1]), --i, --j;
		else if (dp[i][j] == dp[i][j-1]) --j;
		else --i;
	} 
	reverse(ans.begin(), ans.end());
	
	cout << ans << endl;
}

int main()
{
	cin >> a >> b;
	lcs(); print();
}
