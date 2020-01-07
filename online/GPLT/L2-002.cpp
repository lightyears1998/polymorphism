#include <bits/stdc++.h>
using namespace std;

const int maxN = 100500;

bool hasKey[maxN], deleted[maxN], hasDeleted;
int n, head;
int key[maxN], nxt[maxN];

int main()
{
	scanf("%d%d", &head, &n);
	for (int i=0; i<n; ++i)
	{
		int addr; scanf("%d", &addr);
		scanf("%d%d", &key[addr], &nxt[addr]);
	}
	
	for (int cur = head; ~cur; cur = nxt[cur]) {
		if (hasKey[abs(key[cur])]) {
			deleted[cur] = true;
			hasDeleted = true;
		}
		else {
			hasKey[abs(key[cur])] = true;
		}
	}
	
	bool first = true;
	for (int cur = head; ~cur; cur = nxt[cur]) {
		if (!deleted[cur]) {
			if (first) printf("%05d %d", cur, key[cur]), first = false;
			else printf(" %05d\n%05d %d", cur, cur, key[cur]);
		}
	}
	printf(" -1\n");
	
	if (hasDeleted) {
		first = true;
		for (int cur = head; ~cur; cur = nxt[cur]) {
			if (deleted[cur]) {
				if (first) printf("%05d %d", cur, key[cur]), first = false;
				else printf(" %05d\n%05d %d", cur, cur, key[cur]);
			}
		}
		printf(" -1\n");	
	}
}
