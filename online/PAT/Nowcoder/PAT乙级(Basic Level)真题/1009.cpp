#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string head, tail, rslt;

string Minus(string lhs, string rhs)
{
	string rslt = "0000";
	cout << lhs << " - " << rhs << " = ";
	for (int i = 3, ret = 0; i >= 0; i--)
	{
		rslt[i] = lhs[i] - rhs[i] - ret, ret = 0;
		if (rslt[i] < 0) 
			ret = 1, rslt[i] += 10;
		rslt[i] += '0';
	}
	cout << rslt << endl;
	return rslt;
}

signed main()
{
	string str; cin >> str;
	str = string(4 - str.length(), '0') + str;
	sort(str.begin(), str.end());
	
	tail = str;
	reverse(str.begin(), str.end());
	head = str;

	if (head == tail) 
	{
		cout << head << " - " << tail << " = 0000" << endl;
		return 0;
	}

	while ((rslt = Minus(head, tail)) != "6174") 
	{
		sort(rslt.begin(), rslt.end());
		tail = rslt;
		reverse(rslt.begin(), rslt.end());
		head = rslt;
	}
}