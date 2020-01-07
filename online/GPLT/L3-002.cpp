#include <bits/stdc++.h>
using namespace std;

// Reference: https://www.liuchuo.net/archives/2263

const int maxN = 101000;

stack<int> stk;
int bit[maxN];

int lowbit(int x) {
	return x & (-x);
}

void add(int x, int val) {
	while (x < maxN) {
		bit[x] += val;
		x += lowbit(x);
	}
}

int sum(int x) {
	int rslt = 0;
	while (x) {
		rslt += bit[x];
		x -= lowbit(x);
	}
	return rslt;
}

int find() 
{
	int left = 1, right = maxN, k = (stk.size()+1)/2;
	while (left < right) 
	{
		int mid = (left+right) / 2;
		if (sum(mid) >= k)
			right = mid;
		else 
			left = mid+1;
	}
	return left;
}

char buf[20];

int main()
{
	int n; scanf("%d", &n);
	while (n--)
	{
		scanf("%s", buf);
		if (buf[1] == 'o') {
			if (stk.empty()) 
				printf("Invalid\n");
			else {
				int top = stk.top(); stk.pop();
				cout << top << endl;
				add(top, -1); 
			}
		}
		else if (buf[1] == 'e') {
			if (stk.empty()) 
				printf("Invalid\n");
			else
				printf("%d\n", find());
		}
		else if (buf[1] == 'u') {
			int key; scanf("%d", &key);
			stk.push(key);
			add(key, 1);
		}
	}
}
