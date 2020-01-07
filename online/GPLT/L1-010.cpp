#include <bits/stdc++.h>
using namespace std;

int num[3];

int main()
{
	string sign = "->";
	
	cin >> num[0] >> num[1] >> num[2];
	sort(num, num+3);
	cout << num[0] << sign << num[1] << sign << num[2] << endl;
}
