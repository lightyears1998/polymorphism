#include <cstdio>
#include <cmath>
#include <cstring>

int bonus;
char buf[1000];

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif 
	
	while (fgets(buf, sizeof(buf), stdin) != NULL)
	{
		if (strcmp(buf, "#\n") == 0) {
			break;
		}
		if (strcmp(buf, "0\n") == 0) {
			printf("%d\n", bonus); bonus = 0;
			continue;
		}
		int miles; char code; sscanf(buf, "%*s%*s%d %c", &miles, &code);
		switch(code) {
			case 'F': bonus += 2*miles; break;
			case 'B': bonus += miles + round(miles/2.0); break; // miles/2 + (miles&1)
			case 'Y': {
				if (miles <= 500) bonus += 500;
				else bonus += miles;
				break;
			}
		}
	}
}
