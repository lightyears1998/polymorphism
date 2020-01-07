#include <cstdio>
using namespace std;

// 有些时候，命题人给出的数据范围约定是用来吓唬人的 
// 题目输入范围太小时还可以本地打表生成解答数据 

int n;
long long ans; 

void search(long long i, int p)
{
	if (~ans) return; 
	if (p > 18) return;
	if (i % n == 0) {
		ans = i;  
	}
	else {
		search(i*10, p+1);
		search(i*10+1, p+1); 
	} 
} 

int main()
{
	#ifdef LOCAL
	for (int i = 1; i <= 200; ++i)
	{
		n = i;
		ans = -1; search(1, 0);
		printf("%lld\n", ans); 
	} 
	#endif
	
	while (scanf("%d", &n) == 1 && n)
	{
		ans = -1; search(1, 0);
		printf("%lld\n", ans); 
	} 
}
