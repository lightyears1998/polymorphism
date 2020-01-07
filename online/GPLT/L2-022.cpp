#include <bits/stdc++.h>
using namespace std;

// 注意到给出的n个节点可能不全在链表中 

const int maxN = 1000100;

int n, head, tail;
int key[maxN], nxt[maxN];
int seq[maxN];

int main()
{
	cin >> head >> n;
	for (int i=0; i<n; ++i) {
		int addr; cin >> addr;
		cin >> key[addr] >> nxt[addr]; 
	}
	
	for (tail=0; ~head; ++tail) {
		seq[tail] = head, head = nxt[head];
	}
	
	printf("%05d %d", seq[tail-1], key[seq[tail-1]]);
	for (int i=0, j=tail-2; i<=j; ++i, --j) {
		printf(" %05d\n", seq[i]);
		printf("%05d %d", seq[i], key[seq[i]]);
		if (i!=j) {
			printf(" %05d\n", seq[j]);
			printf("%05d %d", seq[j], key[seq[j]]);
		}
	}
	printf(" -1\n");
}
