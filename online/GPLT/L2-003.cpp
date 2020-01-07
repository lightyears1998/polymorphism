#include <bits/stdc++.h>
using namespace std;

struct node
{
	double num;
	double price; 
	bool operator <(const node &a) const
	{
		return price > a.price;
	}
} cake[1010];

int main()
{
	int n; double d; cin >> n >> d;
	for (int i=0; i<n; ++i)
		cin >> cake[i].num;
	
	for (int i=0; i<n; ++i)
		cin >> cake[i].price, cake[i].price /= cake[i].num;
		
	sort(cake, cake+n);
	double tot = 0;
	for (int i=0; d>=0 && i<n; ++i)
	{
		double sold = min(d, cake[i].num);
		tot += cake[i].price * sold;
		d -= sold;
	}
	printf("%.2f\n", tot);
}
