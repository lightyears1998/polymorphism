#include <bits/stdc++.h>
using namespace std;

const int maxN = 1010;

string a, b;
int len[maxN][maxN];
int dir[maxN][maxN];  // ←1  ↖2  ↑3

int lcs(string a, string b)
{
	for (unsigned i = 0; i <= a.size(); ++i)
	{
		for (unsigned j = 0; j <= b.size(); ++j)
		{
			if (i == 0 || j == 0) len[i][j] = 0, dir[i][j] = 0;
			else if (a[i-1] == b[j-1])
			{
				len[i][j] = 1 + len[i-1][j-1];
				dir[i][j] = 2;
			}
			else
			{
				if (len[i-1][j] > len[i][j-1])
					len[i][j] = len[i-1][j], dir[i][j] = 3;
				else 
					len[i][j] = len[i][j-1], dir[i][j] = 1;
			}
		}
	}
	return len[a.size()][b.size()];
}

string restore(string a, string b)
{
	string op; op.resize(lcs(a, b)); 
	
	unsigned i = a.size(), j = b.size(), k = op.size()-1;
	while (dir[i][j]) switch(dir[i][j])
	{
		case 1: j -= 1; break;
		case 2: op[k--] += a[i-1]; i -= 1, j -= 1; break;
		case 3: i -= 1; break;
	}
	return op;
}

int main()
{
	cin >> a >> b;
	cout << restore(a, b) << endl;
}

