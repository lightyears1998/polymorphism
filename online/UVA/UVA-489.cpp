#include <bits/stdc++.h>
using namespace std;

char word[100], guess[100];

int main()
{
	int rnd;
	while (scanf("%d%s%s", &rnd, word, guess) == 3 && ~rnd)
	{
		int chance = 7, win = 0, lose = 0;
		int left=strlen(word);
		for (int i=0; chance && guess[i]; ++i)
		{
			if (strchr(word, guess[i]) != nullptr) {
				for (int j=0; word[j]; ++j) 
					if (word[j] == guess[i]) word[j] = ' ', --left;
			}
			else --chance;
			if (!left) win=1;
			if (!chance) lose=1;
			if (win||lose) break;
		}
		printf("Round %d\n", rnd);
		if (win) printf("You win.\n");
		else if (lose) printf("You lose.\n");
		else printf("You chickened out.\n");
	}
}
