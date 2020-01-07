#include <bits/stdc++.h>
using namespace std;

int main() 
{
	string s; cin >> s;
	
	bool negetive = s[0]=='-';
	bool even     = (s[s.size()-1]-'0')%2==0;
 	
	int dig = 0, cnt2 = 0;
	for (unsigned i=0; i<s.size(); ++i) {
		if (!isdigit(s[i])) continue;
		if (s[i] == '2') ++cnt2;
		++dig;
	}
	
	double fan2 = double(cnt2)/dig*(even?2:1)*(negetive?1.5:1);
	printf("%.2f%%\n", fan2*100);
}
