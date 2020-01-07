#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b; cin >> a >> b;
	int n; cin >> n;
	
	int ca = 0, cb = 0;
	while (n--) {
		int asay, adraw, bsay, bdraw;
		cin >> asay >> adraw >> bsay >> bdraw;
		
		int tot = asay + bsay;
		bool alose = adraw==tot, blose = bdraw==tot;
		
		if (alose&&blose) continue;
		if (alose) {
			ca++;
			if (ca > a) {
				cout << "A" << endl;
				cout << cb << endl;
				break;
			}
		}
		if (blose) {
			cb++;
			if (cb > b) {
				cout << "B" << endl;
				cout << ca << endl;
				break;
			}
		}
	}
}
