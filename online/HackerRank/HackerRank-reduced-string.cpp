#include <bits/stdc++.h>
using namespace std;

stack<char> stk;
string build;

int main()
{
	char ch; while (cin >> ch)
	{
		if (stk.empty()) stk.push(ch);
		else 
		{
			if (ch == stk.top()) stk.pop();
			else stk.push(ch);
		}
	}
	
	while (!stk.empty()) build += stk.top(), stk.pop();
	
	if (build.empty()) cout << "Empty String";
	else for (auto it = build.rbegin(); it != build.rend(); ++it) 
	{
		cout << *it;
	}
	cout << endl;
}

