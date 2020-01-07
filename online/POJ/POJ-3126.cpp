#include <cstdio>
#include <cmath> 
#include <queue>
#include <cstring> 
using namespace std;
 
bool prime[10000];

void init()
{
	prime[1] = false, prime[2] = true;
	for (int i = 3; i < 10000; ++i)
	{
		int range = floor(sqrt(i) + 0.5);
		
		bool ok = true;
		for (int j = 2; ok && j <= range; ++j)
			if (i%j==0) ok = false;
		prime[i] = ok; 
	} 
} 

void split(int cur, int& u, int&v, int&w, int&z)
{
	u = cur / 1000;
	v = cur / 100 % 10;
	w = cur / 10 % 10;
	z = cur % 10; 
} 

int make(int u, int v, int w, int z)
{
	return u * 1000 + v * 100 + w * 10 + z; 
} 

int a, b;
int tme[10000];
queue<int> que; 

void search()
{
	memset(tme, 0x3F, sizeof(tme)); tme[a] = 0; 
	while (!que.empty()) que.pop(); 
	
	que.push(a);
	while (!que.empty())
	{
		int cur = que.front(); que.pop();
		if (cur == b) break; 
		
		int p[4]; split(cur, p[0], p[1], p[2], p[3]);
		for (int i = 0; i < 4; ++i)
		{
			int t = p[i];
			for (int j = 0; j < 10; ++j)
			{
				if(i == 0 && j == 0) continue; 
				
				p[i] = j;
				int nxt = make(p[0], p[1], p[2], p[3]); 
				if (prime[nxt] && tme[nxt] > tme[cur] + 1) {
					que.push(nxt);
					tme[nxt] = tme[cur] + 1;
					
					if (nxt == b) break; 
				} 
			} 
			p[i] = t; 
		} 
	} 
} 

int main()
{
	init();	
	
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &a, &b); 
		search(); 
		
		if (tme[b] != 0x3F3F3F3F)
			printf("%d\n", tme[b]);
		else 
			printf("Impossible\n"); 
	} 
}
