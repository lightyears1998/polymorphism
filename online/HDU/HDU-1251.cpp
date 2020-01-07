#include <bits/stdc++.h>
using namespace std;

const int maxN = 26;
const int base = 'a';

struct trie
{
	int cnt;
	int nxt[maxN];
} node[(int)1e7];

int init()
{
	static int cnt = 0;
	return ++cnt;	
}

void insert(const char *str)
{
	int cur = 0;
	for (unsigned i = 0; str[i] != '\n'; ++i) {
		++node[cur].cnt;
		int id = str[i] - base;
		if (!node[cur].nxt[id]) 
			node[cur].nxt[id] = init();
		cur = node[cur].nxt[id];
	}
	++node[cur].cnt;
}

int search(const char *str)
{
	int cur = 0;
	for (unsigned i = 0; str[i] != '\n'; ++i)
	{
		int id = str[i] - base;
		if (node[cur].nxt[id]) 
			cur = node[cur].nxt[id];
		else return 0;
 	}
 	return node[cur].cnt;
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	
	char buf[maxN];
	while (fgets(buf, sizeof(buf), stdin) != nullptr)
	{
		if (!isalpha(buf[0])) break;
		insert(buf);
	}
	while (fgets(buf, sizeof(buf), stdin) != nullptr)
	{
		printf("%d\n", search(buf));
	} 
}
