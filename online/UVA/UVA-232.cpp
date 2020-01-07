#include <bits/stdc++.h>
using namespace std;

string crossword[15];
int idx[15][15];

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif

	int r, c, kase = 0;
	while (cin >> r >> c)
	{
		memset(idx, 0, sizeof(idx));

		if (kase) cout << endl;
		for (int i = 0; i < r; ++i)
			cin >> crossword[i];
		// 此时如果crossword[i] += '*'，下面的一系列操作就可以极大地简化;

		int tot = 0;
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				if ((j == 0 || crossword[i][j - 1] == '*') && isalpha(crossword[i][j])) {
					idx[i][j] = ++tot; continue;
				}
				if ((i == 0 || crossword[i - 1][j] == '*') && isalpha(crossword[i][j])) {
					idx[i][j] = ++tot; continue;
				}
			}
		}

		cout << "puzzle #" << ++kase << ":" << endl;
		cout << "Across" << endl;
		for (int i = 0; i < r; ++i)
		{
			bool finished = true;
			for (int j = 0; j < c; ++j)
			{
				char cur = crossword[i][j];
				if (isalpha(cur)) {
					if (!finished) cout << cur;
					else {
						cout << setw(3) << idx[i][j] << "." << cur;
						finished = false;
					}
				}
				if (!isalpha(cur) || j + 1 == c) {
					if (!finished)
						cout << endl, finished = true;
				}
			}
		}
		cout << "Down" << endl;
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				if ((i == 0 || crossword[i - 1][j] == '*') && isalpha(crossword[i][j]))
				{
					cout << setw(3) << idx[i][j] << ".";
					for (int k = i; k < r && crossword[k][j] != '*'; ++k)
					{
						cout << crossword[k][j];
					}
					cout << endl;
				}
			}
		}
	}
}
