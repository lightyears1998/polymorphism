// 竖式问题
// 暴力枚举法
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    char s[10], buf[99];
    while (scanf("%s", s) == 1)
    {
        int count = 0;
        for (int abc = 111; abc <= 999; abc++)
        {
            for (int e = 1; e <= 9; e++)
            {
                for (int f = 1; f <= 9; f++)
                {
                    sprintf(buf, "%d%d%d%d%d%d", abc, e, f, abc * e, abc * f, abc * (e * 10 + f));
                    bool ok = true;
                    for (int i = 0; i < strlen(buf); i++)
                    {
                        if (strchr(s, buf[i]) == NULL) ok = false;
                    }
                    if (ok)
                    {
                        printf("<%d>\n", ++count);
                        printf("%5d\nX  %d%d\n-----\n%5d\n%4d \n-----\n%5d\n\n", abc, e, f, abc * f, abc * e, abc * (e * 10 + f));
                    }
                }
            }
        }

        printf("The number of solutions: %d\n", count);
    }
}
