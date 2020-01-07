#include <cstdio>
#include <cstring>
using namespace std;

const int maxN = 1010;

int cell[maxN][maxN];

int lowbit(int x)
{
	return x&(-x);
}

void add(int x, int y)
{
	for (int i = x; i<maxN; i+=lowbit(i))
		for (int j = y; j<maxN; j+=lowbit(j))
			++cell[i][j];
}

int get(int x, int y)
{
	int rslt = 0;
	for (int i = x; i; i-=lowbit(i))
		for (int j = y; j; j-=lowbit(j))
			rslt += cell[i][j];
	return rslt;
}

int main()
{
	int x; scanf("%d", &x);
	while (x--)
	{
		memset(cell, 0, sizeof(cell));
		
		int n, t; scanf("%d%d", &n, &t);
		while (t--)
		{
			char ch; scanf(" %c", &ch);
			if (ch == 'C')
			{
				int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				add(x1, y1);
				add(x2+1, y1);
				add(x1, y2+1);
				add(x2+1, y2+1); 
			}
			if (ch == 'Q')
			{
				int x, y; scanf("%d%d", &x, &y);
				puts(get(x, y)&1 ? "1" : "0");	
			} 
		}
		
		if (x) putchar('\n');
	}
}
