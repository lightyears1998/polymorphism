#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int d[110];
int p[110][110];

int get(int front, int back)
{
	return d[back] - d[front-1];
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	
	cin.tie(0); ios_base::sync_with_stdio(false); 
	int n; cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> d[i], d[i] += d[i-1];
	
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j + i - 1 <= n; ++j)
		{
			p[j][j+i-1] = p[j+1][j+i-1] + get(j, j+i-1);
			for (int k = j+1; k < j+i-1; ++k)
			{
				p[j][j+i-1] = min(p[j][j+i-1], p[j][k] + p[k+1][j+i-1] + get(j, j+i-1)); 
			} 
		}
	}
	
	cout << p[1][n] << endl;
}

