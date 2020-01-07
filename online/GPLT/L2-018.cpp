#include <bits/stdc++.h>
using namespace std;

vector<double> a; int ah; // 被除数（余数） 
vector<double> b; int bh; // 除数 
vector<double> q; int qh; // 商 

// 非零项的项数，多项式的次数，储存多项式的vector 
void input(int &h, vector<double> &v)
{
	int n; cin >> n >> h;
	int cur; cin >> cur; v.push_back(cur); --n;
	for (int i=h-1; i>=0; --i) 
	{
		int e;
		if (n) cin >> e; 
		else e = 0;
		while (e != i) {
			--i;
			v.push_back(0);
		}
		if (n) {
			cin >> cur;
			v.push_back(cur); 
			--n;
		}
		else v.push_back(0); 
	}
}

// 输出多项式 
void output(int h, vector<double> &v)
{
	cout.flags(cout.fixed);
	cout.precision(1);
	int tot = 0;	
	for (double d : v) {
		if (abs(d) >= 0.1) ++tot;
	}
	cout << tot;
	if (tot != 0) {
		for (unsigned i=0; i<v.size(); ++i) {
			if (abs(v[i]) >= 0.1) cout << ' ' <<  h-i << ' ' << v[i];
		}
		cout << endl;
	}
	else {
		cout << " 0 0.0" << endl;
	}
}

int main()
{
	input(ah, a);
	input(bh, b);
	
	qh = ah-bh;
	for (int i=0; i<=qh; ++i) {
		double cur = a[i]/b[0];
		q.push_back(cur);
		for (unsigned j=0; j<b.size(); ++j) {
			a[i+j] -= b[j]*cur;
		}
	}	
	
	output(qh, q);
	output(ah, a);
}
