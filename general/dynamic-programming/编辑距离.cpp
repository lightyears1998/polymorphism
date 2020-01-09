#include <bits/stdc++.h>
using namespace std;

const int maxN = 1010;

int dis[maxN][maxN];

int edit_distance(string &a, string &b)
{
	for (unsigned i=0; i<=a.size(); ++i)
	{
		for (unsigned j=0; j<=b.size(); ++j)
		{
			if (i == 0 || j == 0) {
				dis[i][j] = max(i, j);
				continue;
			}
			dis[i][j] = dis[i-1][j-1] + 1-(a[i-1]==b[j-1]);
			int candidate = min(dis[i-1][j]+1, dis[i][j-1]+1);
			dis[i][j] = min(candidate, dis[i][j]);
		}
	}
	return dis[a.size()][b.size()];
}

int main()
{
	string a, b; cin >> a >> b;
	edit_distance(a, b);
	cout << dis[a.size()][b.size()] << endl;
}
