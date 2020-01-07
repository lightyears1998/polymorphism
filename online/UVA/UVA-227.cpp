#include <bits/stdc++.h>
using namespace std;

char puzzle[5][5];

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	int kase = 0, ch;
	while ((ch = getchar()) && ch != 'Z') 
	{
		if (kase) cout << endl;
		int x, y;
		
		int pos = 0;
		while (true)
		{
			if (ch == '\n') 
				ch = getchar();
			if (ch == ' ') {
				x = pos / 5, y = pos % 5;
			} 
			puzzle[pos / 5][pos % 5] = ch, pos++;
			if (pos ==  25) break;
			else ch = getchar();
		}
			
		bool finished = false, legal = true;
		string cmd;
		while (!finished && cin >> cmd)
		{
			for (char ch : cmd)
			{
				switch(ch) 
				{
					case 'A': {
						if (x - 1 >= 0) swap(puzzle[x - 1][y], puzzle[x][y]), x -= 1; 
						else legal = false;
						break;
					}
					case 'B': {
						if (x + 1 < 5) swap(puzzle[x + 1][y], puzzle[x][y]), x += 1; 
						else legal = false;
						break;
					}
					case 'R': {
						if (y + 1 < 5) swap(puzzle[x][y + 1], puzzle[x][y]), y += 1; 
						else legal = false;
						break;
					}
					case 'L': {
						if (y - 1 >= 0) swap(puzzle[x][y - 1], puzzle[x][y]), y -= 1; 
						else legal = false;
						break;
					}
					case '0': {
						finished = true;
						getchar();
						break;
					}
					default: legal = false;
				}
			}
		}
		
		printf("Puzzle #%d:\n", ++kase);
		if (legal) 
		{
			for (int i = 0; i < 25; ++i)
			{
				printf("%c", puzzle[i/5][i%5]);
				i % 5 == 4 ? printf("\n") : printf(" ");
			}
		}
		else printf("This puzzle has no final configuration.\n");
	}
}

