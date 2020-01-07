#include <cstdio>
#include <vector> 
#include <queue>
#include <cstring> 
#include <utility> 
using namespace std;

const char * msg[] = {
	"FILL(1)", "FILL(2)",
	"DROP(1)", "DROP(2)",
	"POUR(1,2)", "POUR(2,1)",
};

int pot[3], cur[3], nxt[3], obj;
int tme[101][101];
queue<pair<int, int>> que; 
vector<int> op[101][101];   

void init()
{
	memset(tme, 0x3F, sizeof(tme)); 
	tme[pot[1]][pot[2]] = 0;
	
	while (!que.empty()) que.pop();
	que.push(make_pair(pot[1], pot[2])); 
	
	for (int i = 0; i < 101; ++i) 
		for (int j = 0; j < 101; ++j) 
			op[i][j].clear();
} 

void check()
{
	
} 

void fill(int i)
{
	if (i == 1) 
		nxt[1] = pot[i], nxt[2] = cur[2]; 
	else 
		nxt[1] = cur[1], nxt[2] = pot[2]; 
		
	if (tme[nxt[1]][nxt[2]] > tme[cur[1]][cur[2]] + 1) {
		tme[nxt[1]][nxt[2]] = tme[cur[1]][cur[2]] + 1;
		que.push(make_pair(nxt[1], nxt[2]));
	} 
}

void drop(int i)
{
	if (i == 1) 
		nxt[1] = 0, nxt[2] = cur[2]; 
	else 
		nxt[1] = cur[1], nxt[2] = 0;
		
	if (tme[nxt[1]][nxt[2]] > tme[cur[1]][cur[2]] + 1) {
		tme[nxt[1]][nxt[2]] = tme[cur[1]][cur[2]] + 1;
		que.push(make_pair(nxt[1], nxt[2]));
	} 
}

void pour(int i, int j)
{
	
} 

void search()
{
	while (!que.empty())
	{
		cur[1] = que.front().first;
		cur[2] = que.front().second;
		que.pop();
		
		fill(1), fill(2);
		drop(1), drop(2);
		pour(1, 2), pour(2, 1);
	}
} 

int main() 
{
	while (scanf("%d%d%d", &pot[1], &pot[2], &obj) == 3)
	{
		init(); 
		search();
	} 
}
