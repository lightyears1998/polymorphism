#include <cstdio>
using namespace std;

const int slen = 26;
const int maxN = 10020030;
const int base = 'a';

int n = 0;
char text[1010][25];

struct {
	int cnt;
	int nxt[slen];
} trie[maxN];

int init()
{
	static int cnt = 0;
	return ++cnt;
}

void insert(const char *str)
{
	int cur = 0;
	for (int i = 0; str[i]; ++i)
	{
		++trie[cur].cnt;
		int id = str[i] - base;
		if (!trie[cur].nxt[id]) trie[cur].nxt[id] = init();
		cur = trie[cur].nxt[id];
	}
	++trie[cur].cnt;
}

void query(char *str)
{
	int cur = 0, cnt = 0;
	for (int i = 0; str[i]; ++i)
	{
		if (trie[cur].cnt == 1) {
			printf("%s ", str);
			str[cnt] = 0;
			printf("%s\n", str);
			return;
		}
		else {
			++cnt, cur = trie[cur].nxt[str[i]-base];
		}
	}
	printf("%s %s\n", str, str);
}

int main()
{
	while (scanf("%s", text[n]) == 1) ++n;
	for (int i = 0; i < n; ++i)
		insert(text[i]);
	for (int i = 0; i < n; ++i)
		query(text[i]);
}
