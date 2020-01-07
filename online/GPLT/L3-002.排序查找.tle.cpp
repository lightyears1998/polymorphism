#include <bits/stdc++.h>
using namespace std;

const int maxN = 101000;

int head;
int stk[maxN], vis[maxN];

void init() {
	memcpy(vis, stk, sizeof(vis));
}

int main()
{
	int n; cin >> n;
	
	string s; while (cin >> s)
	{
		if (s == "Pop") {
			if (!head) cout << "Invalid" << endl;
			else cout << stk[--head] << endl;
		}
		else if (s == "Push") {
			cin >> stk[head++];
		}
		else if (s == "PeekMedian") {
			if (head == 0) cout << "Invalid" << endl;
			else {
				int k = (head%2 ? (head+1)/2 : head/2);
				init();
				nth_element(vis, vis+k-1, vis+head);
				cout << vis[k-1] << endl;	
			}
		}
	}
}
