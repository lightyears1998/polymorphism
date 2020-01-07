#include <bits/stdc++.h>
using namespace std;
using pi = pair<unsigned, int>;

int tot;
stack<unsigned> pt;
stack<pi> area;

// Stack方案
// “\\//”与 “\/\/”差别在于下降的起点不同

int main()
{
	string contr; cin >> contr;
	
	for (unsigned i = 0; i < contr.size(); ++i) switch(contr[i])
	{
		case '\\': {
			pt.push(i);
			break;
		}
		case '/' : {
			if (!pt.empty())
			{
				unsigned j = pt.top(); pt.pop();
				int ar = i - j; tot += ar;
				while (!area.empty())
				{
					pi pre = area.top();
					if (pre.first > j) {
						ar += pre.second;
						area.pop();
					}
					else break;
				}
				area.push({j, ar});
 			}
			break;
		}
	}
	
	cout << tot << endl << area.size();
	deque<int> ans;
	while (!area.empty())
	{
		ans.push_front(area.top().second); area.pop();
	}
	for (int i : ans) cout << ' ' << i;
	cout << endl;
}

