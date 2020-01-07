#include <cstdio>
#include <cstring>
#include <queue> 
#include <algorithm> 
using namespace std;

int n, k;
int tme[100100]; 
queue<int> que; 

void search()
{
	while (!que.empty())
	{
		int nxt, cur = que.front(); que.pop(); 
		if (cur == k) break; 
		
		nxt = cur * 2;
		if (nxt < 100100 && abs(nxt - k) < abs(cur - k) && tme[nxt] > tme[cur] + 1) {
			que.push(nxt);
			tme[nxt] = tme[cur] + 1; 
		}
		
		nxt = cur - 1;
		if (nxt >= 0 && tme[nxt] > tme[cur] + 1) {
			que.push(nxt);
			tme[nxt] = tme[cur] + 1; 
		} 
		
		nxt = cur + 1;
		if (nxt < 100100 && nxt <= k && tme[nxt] > tme[cur] + 1) {
			que.push(nxt);
			tme[nxt] = tme[cur] + 1; 
		} 
	} 
}

int main()
{
	while (scanf("%d%d", &n, &k) == 2)
	{
		memset(tme, 0x3F, sizeof(tme)); tme[n] = 0; 
		while (!que.empty()) que.pop();
		que.push(n); 
		
		search(); 
		printf("%d\n", tme[k]); 
	} 
} 
