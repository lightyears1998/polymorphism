#include <cstdio>
#include <algorithm>
using namespace std;

// UVA - Ñ¡°ÎÓÂÊ¿ 'Vice Versa'

int execute(int n)
{
	int cnt = 1;
	while (n != 1)
	{
		if (n%2) n = 3*n+1;
		else n /= 2;
		++cnt;
	}
	return cnt;
} 

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	int a, b;
	while (scanf("%d%d", &a, &b) == 2)
	{
		printf("%d %d", a, b);
		if (a > b) swap(a, b);
		
		int mx = execute(a);
		for (int i = a+1; i <= b; ++i)
		{
			mx = max(execute(i), mx);
		}
		printf(" %d\n", mx);
	}	
}

