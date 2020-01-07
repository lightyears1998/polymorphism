#include <bits/stdc++.h>
using namespace std;

double cross_product(double x1, double y1, double x2, double y2)
{
	return x1*y2 - x2*y1;
}

int main()
{
	int t; cin >> t;
	while (t--) 
	{
		double x1, y1, x2, y2, x3, y3, x4, y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		
		bool cross = 
			cross_product(x2-x1, y2-y1, x3-x1, y3-y1)*cross_product(x2-x1, y2-y1, x4-x1, y4-y1) <= 0 &&
			cross_product(x3-x4, y3-y4, x2-x4, y2-y4)*cross_product(x3-x4, y3-y4, x1-x4, y1-y4) <= 0;
		cout << (cross ? "Yes" : "No") << endl; 
	}
}
