#include <bits/stdc++.h>
using namespace std;

int wght[] {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
int z[] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
string m = "10X98765432";

vector<string> prob;

int main()
{
	int n; cin >> n;
	while (n--) {
		string str; cin >> str;
		int sum = 0;
		
		for (unsigned i=0; i<17; ++i) {
			int cur;
			if (isdigit(str[i])) cur = str[i]-'0';
			else if (str[i] == 'X') cur = 10;
			else { sum = -1; break; }
			
			sum += cur*wght[i];
		}
		
		if (sum == -1) {
			prob.push_back(str); continue;
		}
		
		sum %= 11;
		int pos = find(z, z+11, sum)-z;
		if (m[pos] != str[17]) prob.push_back(str);
	}
	
	if (prob.size()) {
		for (string &s : prob) {
			cout << s << endl;
		}
	}
	else cout << "All passed" << endl;
}
