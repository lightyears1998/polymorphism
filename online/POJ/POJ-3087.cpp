#include <cstdio>
#include <string> 
#include <map> 
#include <queue> 
using namespace std;

string combine(string &a, string &b)
{
	string rslt; 
	for (int i = 0; i < a.size(); ++i)
		rslt += b[i], rslt += a[i]; 
	return rslt; 
} 

string shuffle(string& s)
{
	string a = s.substr(0, s.size()/ 2);
	string b = s.substr(s.size()/2); 
	return combine(a, b); 
}

string a, b, c;
map<string, int> tme; 
queue<string> que; 

void search()
{
	string bgn = combine(a, b); 
	
	tme.clear(); tme[bgn] = 1;
	que.push(bgn); 
	while (!que.empty())
	{
		string cur = que.front(); que.pop();		
		if (cur == c) break;
 
 		string nxt = shuffle(cur); 
		map<string, int>::iterator it = tme.find(nxt);
		if (it != tme.end()) break;
		else que.push(nxt), tme[nxt] = tme[cur] + 1; 
	} 
} 

int main()
{	
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);	
	#endif 

	int kase; scanf("%d", &kase);
	for (int k = 1; k <= kase; ++k)
	{
		printf("%d ", k);
		
		int n; scanf("%d", &n); 
		a.resize(n+1), b.resize(n+1), c.resize(2*n+1);
		scanf("%s", &a[0]), scanf("%s", &b[0]), scanf("%s", &c[0]); 
		a.resize(n), b.resize(n), c.resize(2*n); 
		
		search(); 
		
		map<string, int>::iterator it = tme.find(c);
		if (it == tme.end())
			printf("-1\n"); 
		else 
			printf("%d\n", it->second); 
	} 
} 
