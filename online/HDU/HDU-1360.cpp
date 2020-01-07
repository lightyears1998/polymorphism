#include <bits/stdc++.h>
using namespace std;

int tot;
string mark = ".?!";

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif

	bool inword = false, insentence = false;
	int ch; while ((ch = getchar()) != EOF)
	{
		if (isalpha(ch))
		{
			if (!insentence) {
				if (islower(ch)) ++tot;
			}
			else if (inword) {
				if (isupper(ch)) ++tot;
			}
			inword = true, insentence = true;
		}
		else if (mark.find(ch) != (size_t)-1) {
			inword = false, insentence = false;
		}
		else inword = false;
	}
	printf("%d\n", tot);
}

