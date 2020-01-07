#include <bits/stdc++.h>
using namespace std; 

map<int, int> gene = {
	pair<int, int>('A', 0), pair<int, int>(0, 'A'),
	pair<int, int>('C', 1), pair<int, int>(1, 'C'),
	pair<int, int>('G', 2), pair<int, int>(2, 'G'),
	pair<int, int>('T', 3), pair<int, int>(3, 'T'),
}; 
int cnt[1100][4]; 

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin); 
	freopen("out.txt", "w", stdout);
	#endif 
	
	int t; cin >> t;
	while (t--)
	{
		memset(cnt, 0, sizeof(cnt)); 
		int m, n; cin >> m >> n; 
		
		for (int i = 0; i < m; ++i)
		{
			string dna; cin >> dna;
			for (int j = 0; j < n; ++j)
			{
				++cnt[j][gene[dna[j]]]; 
			} 
		}
		
		string ans; int tot = 0; 
		for (int i = 0; i < n; ++i)
		{
			int mx = *max_element(cnt[i], cnt[i] + 4);
			for (int j = 0; j < 4; ++j) if (cnt[i][j] == mx)
			{
				ans += gene[j]; 
				tot += m - cnt[i][j]; 
				break; 
			} 
		}
		cout << ans << endl << tot << endl; 
	} 
} 
