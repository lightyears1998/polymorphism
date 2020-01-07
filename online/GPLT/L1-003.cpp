#include <bits/stdc++.h>
using namespace std;

string str;

int cnt[10];

int main()
{
	cin >> str;
	for (char ch : str) {
		cnt[ch-'0']++;
	}
	
	for (int i=0; i<10; ++i) {
		if (cnt[i]) cout << i << ":" << cnt[i] << endl;
	}
}
