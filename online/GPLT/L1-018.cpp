#include <bits/stdc++.h>
using namespace std;

int main()
{
	int hh, mm; scanf("%d:%d", &hh, &mm);
	
	bool dang = !(hh < 12 || (hh==12&&mm==0));
	
	if (dang) {
		int count = hh-12;
		if (mm) count++;
		while (count--) cout << "Dang";
		cout << endl;
	}
	else {
		printf("Only %02d:%02d.  Too early to Dang.\n", hh, mm);
	}
	
}
