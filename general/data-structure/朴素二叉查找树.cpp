#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e8+7;

int head, tot;
vector<int> cache;

struct Node {
	int val;
	int l, r, fa;
} node[maxN];

// Lambda function to remove a child from its father
auto rmchild = [](int sn, int fa) {
	if (node[fa].l == sn) node[fa].l = 0;
	if (node[fa].r == sn) node[fa].r = 0;
};

// Replace dst with src node and keep the property of tree
auto rpnode = [](int dst, int src) {
	node[dst].val = node[src].val;
	node[dst].l = node[src].l;
	node[dst].r = node[src].r;
	node[node[src].l].fa = dst;
	node[node[src].r].fa = dst; 
};

// Clean up
void init()
{
	tot = 0;
	memset(node, 0, sizeof(node));
}

// Assign new node with father and value
int assign(int fa, int val) 
{
	Node &cur = node[++tot];
	cur.fa = fa, cur.val = val;
	return tot;
}

// Insert certain value into the tree
void insert(int x)
{
	if (head == 0) {
		head = assign(0, x);
		return;
	}
	int cur = head;
	while (true)
	{
		if (node[cur].val == x) return;
		if (node[cur].val > x) {
			int nxt = node[cur].l;
			if (!nxt) {
				node[cur].l = assign(cur, x);
				return;
			}
			else cur = nxt;
		}
		else {
			int nxt = node[cur].r;
			if (!nxt) {
				node[cur].r = assign(cur, x);
			}
			else cur = nxt;
		}
	}
}

// Return true when find the specific value in the tree
bool find(int x)
{
	if (head == 0) return false;
	int cur = head;
	while (true)
	{
		if (x == node[cur].val) return true;
		if (x > node[cur].val) {
			int nxt = node[cur].r;
			if (!nxt) return false;
			cur = nxt;
		} 
		else {
			int nxt = node[cur].l;
			if (!nxt) return false;
			cur = nxt;
		}
	}
}

// Delete certain element from tree
void remove(int x)
{
	if (head == 0) return;
	
	int cur = head;
	while (true)
	{
		if (node[cur].val == x) {
			if (node[cur].l == 0 && node[cur].r == 0) {
				rmchild(cur, node[cur].fa);
				if (cur == head) head = 0;
			}
			else if (node[cur].l == 0) {
				rpnode(cur, node[cur].r);
			}
			else if (node[cur].r == 0) {
				rpnode(cur, node[cur].l);
			} 
			else 
			{
				int nxt = node[cur].l;
				while (node[nxt].r != 0) nxt = node[nxt].r;
				rmchild(nxt, node[nxt].fa);
				node[cur].val = node[nxt].val;
			}
			return;
		}
		if (node[cur].val > x) {
			int nxt = node[cur].l;
			if (nxt) {
				cur = nxt;
			}
			else return;
		}
		if (node[cur].val < x) {
			int nxt = node[cur].r;
			if (nxt) {
				cur = nxt;
			}
			else return;
		} 
	}
}

// Inorder-travelal
void walk(int rt = head)
{
	if (!rt) return;
	walk(node[rt].l);
	cache.push_back(node[rt].val);
	walk(node[rt].r);
}

// Display content
void show()
{
	int cnt = 0;
	for (int x : cache)
	{
		cout << x;
		++cnt;
		cout << (cnt % 5 ? ' ' : '\n');
	}
	if (cnt % 5) cout << endl;
	
	cache.clear();
}

int main()
{
	int n; cin >> n;
	while (n--) insert(rand());
	
	walk();
	show();
	
	for (int k=10; k; --k)
	{
		cout << k << ":";
		int q; cin >> q;
		remove(q);
		walk(); show();
	}
	
	for (int k=10; k; --k) insert(rand());
	walk(); show();
} 
