#include <bits/stdc++.h>
using namespace std;

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	
	string a, b;
	while (cin >> a >> b)
	{
		if (a.size() < b.size()) swap(a, b);
		
		int forward = 0, backward = 0;
		while (true)
		{
			bool ok = true; 
			for (int i = 0; i < a.size(); ++i)
			{
				if (i - forward >= 0 && i - forward < b.size()) {
					char sum = a[i] + b[i - forward] - '0';
					if (sum > '3') ok = false; 
				} 
			} 
			if (ok) break;
			else forward++; 
		} 
		
		while (true)
		{
			bool ok = true; 
			for (int i = 0; i < a.size(); ++i)
			{
				if (i + backward >= 0 && i + backward < b.size()) {
					char sum = a[i] + b[i + backward] - '0';
					if (sum > '3') ok = false; 
				} 
			} 
			if (ok) break;
			else backward++; 
		}
		
		cout << min(max(a.size(), b.size() + forward), a.size() + backward) << endl; 
	} 
}
