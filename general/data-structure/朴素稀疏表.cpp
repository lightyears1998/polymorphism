#include <bits/stdc++.h>
using namespace std; 

// Keep a good counting. 

const int maxN = 100000;

int st[maxN][32];

vector<int> num;

void init()
{
	int len = num.size();
	int bound = ceil(log2(num.size()));
	for (int i = 0; i < len; ++i)
		st[i][0] = num[i];
	
	for (int i = 1; i <= bound; ++i)
		for (int j = 0; j < len; ++j)
			st[j][i] = min(st[j][i-1], st[min(j+(1<<(i-1)), len-1)][i-1]);
}

// Minimum value of [x, y].
int query(int x, int y)
{
	int k = floor(log2(y-x+1));
	return min(st[x][k], st[y-(1<<k)+1][k]);
}

int main()
{
	for (int i = 0; i < 5; ++i)
		num.push_back(rand());
	
	init();
	
	for (int i : num) 
		cout << i << ' ';
	cout << endl;
	
	for (unsigned i = 0; i < num.size(); ++i)
		for (unsigned j = i; j < num.size(); ++j)
			cout << i << ' ' << j << ' ' << query(i, j) << endl;
}
