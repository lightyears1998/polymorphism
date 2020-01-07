#include <bits/stdc++.h>
using namespace std;

// 结论错误
// 前一个质数并不是当前合数的最大质因数

const int maxN = 1000010;
bool isprime[maxN];
int pos[maxN], prime[maxN];

void seive()
{
	memset(isprime, true, sizeof(isprime));
	isprime[0] = isprime[1] = false;
	int cnt = 1, tot = 0;
	for (int i=2; i<maxN; ++i) {
		if (isprime[i]) {
			prime[tot++] = i;
			pos[i] = cnt++;
		}
		for (int j=0; j<tot && i*prime[j] < maxN; ++j) {
			isprime[i*prime[j]] = false;
			if (i % prime[j] == 0) break;
		}
	}
}

int main()
{
	seive();

	int n;
	while (scanf("%d", &n) == 1){
		if (n == 1) {
			printf("0\n"); continue;
		}
		while (pos[n] == 0) n--;
		printf("%d\n", pos[n]);
	}
}
