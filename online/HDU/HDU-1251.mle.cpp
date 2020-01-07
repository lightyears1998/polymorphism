#include <bits/stdc++.h>
using namespace std;

const int maxN = 30;
const int base = 'a';

// Unkonwn Reason 
struct trie
{
	int cnt;
	trie *nxt[maxN];
} head;

void insert(const string& s)
{
	trie *cur = &head;
	for (unsigned i = 0; i < s.size(); ++i) {
		++(cur->cnt);
		int id = s[i]-base;
		if (cur->nxt[id]) {
			cur = cur->nxt[id];
		}
		else {
			trie *child = (trie *)calloc(1, sizeof(trie));
			cur->nxt[id] = child;
			cur = child;
		}
	}
	++(cur->cnt);
}

int search(const string& s)
{
	trie *cur = &head;
	for (unsigned i = 0; i < s.size(); ++i)
	{
		int id = s[i] - base;
		if (cur->nxt[id]) {
			cur = cur->nxt[id];
		}
		else {
			return 0;
		}
 	}
 	return cur->cnt;
}

int main()
{
	string s;
	while (getline(cin, s))
	{
		if (s.empty()) break;
		insert(s);
	}
	while (getline(cin, s))
	{
		cout << search(s) << endl;
	} 
}
