/* 开灯问题 */
#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 1000;

int main()
{
    bool lights[MAXN];
    int n, k;
    while (cin >> n >> k)
    {
        memset(lights, 0, sizeof(lights));
        for (int i = 1; i <= k; i++)
        {
            int j = i;
            while (j <= n)
            {
                lights[j] = !lights[j];
                j += i;
            }
        }
        int cnt = 0;
        bool first = true;
        for (int i = 1; i <= n; i++)
        {
            if (lights[i]) {
                if (!first) cout << " ";
                else first = false;
                cout << i;
            }
        }
        cout << endl;
    }
}
