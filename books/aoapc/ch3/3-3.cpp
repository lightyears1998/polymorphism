/* 蛇形填数 */
#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 20;        // 不能定义得太大

/**
 *       * ------ y
 *       |
 *       |
 *       |
 *       x
***/

int main()
{
    int num[MAXN][MAXN], n;
    while (cin >> n)
    {
        memset(num, 0, sizeof(num));
        int x, y, tot;
        tot = num[x=0][y=n-1] = 1;
        while (tot < n * n)
        {
            while (x < n - 1 && !num[x+1][y]) num[++x][y] = ++tot;
            while (y > 0 && !num[x][y-1]) num[x][--y] = ++tot;
            while (x > 0 && !num[x-1][y]) num[--x][y] = ++tot;
            while (y < n - 1 && !num[x][y+1]) num[x][++y] = ++tot;
        }

        for (int i = 0; i < n; i++)
        {
            cout << num[i][0];
            for (int j = 1; j < n; j++)
            {
                cout << " " << num[i][j];
            }
            cout << endl;
        }
    }
}
