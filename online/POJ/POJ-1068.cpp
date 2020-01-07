#include <stack>
#include <vector>
#include <iostream>
using namespace std;

stack<int> stk;
vector<int> build;

int main()
{
	int t; cin >> t;
	while (t--)
	{
		while (stk.size()) stk.pop();
		build.clear();
		
		int n; cin >> n;
		int tot = 0;
		for (int i = 0; i < n; ++i)
		{
			int k; cin >> k;
			
			k -= tot, tot += k;
			while (k--) stk.push(0);
			
			int t = 1;
			while (true)
			{
				int cur = stk.top(); stk.pop();
				if (cur == 0) {
					stk.push(t);
					build.push_back(t);
					break;
				}
				else t += cur;
			}
		}
		
		for (int i = 0; i < build.size(); ++i) {
			cout << (i ? " " : ""); 
			cout << build[i];
		}
		cout << endl;
	}
}
