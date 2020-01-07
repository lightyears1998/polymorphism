#include <bits/stdc++.h>
using namespace std;

char build[1025][1025];

void make(int x, int y, int n)
{
	int len = (n ? 8<<(n-1) : 4);
	
	// Head
	build[x][y] = '+';
	for (int i = 1; i < len-1; ++i)
		build[x][y+i] = '-';
	build[x][y+len-1] = '+';
	
	// Boarder and Slide Line
	int left = len/2, right = len/2+1;
	for (int i = 1; i < len-1; ++i)
	{
		build[x+i][y] = '|';
		build[x+i][y+len-1] = '|';
		for (int j = 1; len!=4 && j<len-1; ++j)
		{
			if (j==left) {
				if (i!=1) build[x+i][y+j-1] = '/';
				--left;
				if (left-2==0) left = -1;
				continue;
			}
			if (j==right) {
				if (i!=1) build[x+i][y+j-1] = '\\';
				++right;
				if (right+1==len) right = -1;
				break;
			}
		}
	}
	
	// Bottom
	build[x+len-1][y] = '+';
	for (int i = 1; i < len-1; ++i)
		build[x+len-1][y+i] = '-';
	build[x+len-1][y+len-1] = '+';
	
	if (n!=0) make(x+len/2, y+len/2/2, n-1);
}

void draw(int n)
{
	for (int i = 1; i <= 8<<(n-1); ++i)
	{
		for (int j = 1; j <= 8<<(n-1); ++j)
		{
			if (build[i][j] == '\0') cout << ' ';
			else cout << build[i][j];
		}
		cout << endl;
	}
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	int t; cin >> t;
	while (t--)
	{
		memset(build, 0, sizeof(build));
		
		int n; cin >> n;
		make(1, 1, n);
		draw(n);
	}
}
