#include <vector>
#include <string>
#include <iostream>
#include <algorithm> 
#include <functional>
using namespace std;

int main()
{	
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		
		vector<int> ref(n);
		vector<string> vec(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> vec[i];
			ref[i] = vec[i].size()*100 + i;
		}
		sort(ref.begin(), ref.end(), greater<int>());
		
		unsigned mx = 0;
		for (int i = 0; !mx && i < n; ++i)
		{
			string s = vec[ref[i]%100];
			for (int j = 0; j < n; ++j)
			{
				if (vec[ref[j]%100].size() < s.size()) break;
				if (~vec[ref[j]%100].find(s)) {
					mx = s.size(); break;
				}
				reverse(s.begin(), s.end());
				if (~vec[ref[j]%100].find(s)) {
					mx = s.size(); break;
				}
			}
		}
		cout << mx << endl;
	}
}

