#include <bits/stdc++.h>
using namespace std;

char buf1[100100], buf2[100100];

int get(char *str)
{
	int tmp = 0;
	int i = 0; // if (str[i] == '+') ++i;
	while (str[i] && str[i]!='\n')
	{
		if (isdigit(str[i])) {
			tmp = tmp*10 + str[i]-'0';
			if (tmp > 1000) return 0;
		}
		else return 0;
		++i;
	}
	return tmp;
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	
	scanf("%s ", buf1); fgets(buf2, sizeof(buf2), stdin);
	int a = get(buf1), b = get(buf2);
	
	// if (buf2[0] == 0) swap(a, b);
	
	if (a == 0) cout << '?';
	else cout << a;
	
	cout << " + ";
	
	if (b == 0) cout << '?';
	else cout << b;
	
	cout << " = ";
	if (!(a == 0 || b == 0)) cout << a + b;
	else cout << '?';
	cout << endl;
}
