#include <bits/stdc++.h>
using namespace std;

// Reference:
// https://vjudge.net/solution/12806072

int main()
{
	unsigned n, k; cin >> n >> k;
	string s; cin >> s;
	set<char> dic(s.begin(), s.end());
	
	if (k <= n)
	{
		s.resize(k);
		while (s.size())
		{
			auto it = upper_bound(dic.begin(), dic.end(), s.back());
			s.pop_back();
			if (it != dic.end())
			{
				s.push_back(*it);
				break;
			}
		}
	}
	if (s.size() < k) s.resize(k, *dic.begin());	
	cout << s << endl;
}
