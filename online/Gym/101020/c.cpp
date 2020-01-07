#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

const int MX = 120;
bool occupied[MX][MX];

int main()
{
    int t; cin >> t;
    while (t--)
    {
        memset(occupied, false, sizeof(occupied));

        int n; cin >> n;
        while (n--)
        {
            int i, j, k; cin >> i >> j >> k;
            for (int x = 1; x <= k; ++x)
                for (int y = i + 1; y <= j; ++y)
                    occupied[x][y] = true;
        }

        int tot = 0;
        for (int i = 1; i < MX; ++i)
            for (int j = 1; j < MX; ++j)
                if (occupied[i][j]) ++tot;

        cout << tot << endl;
    }
}
