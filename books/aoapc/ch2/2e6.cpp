// 来自深度优先搜索的黑科技get~
#include <iostream>
#include <algorithm>
using namespace std;

int num[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

void check()
{
    int a = num[0] * 100 + num[1] * 10 + num[2];
    int b = num[3] * 100 + num[4] * 10 + num[5];
    int c = num[6] * 100 + num[7] * 10 + num[8];
    if (a * 2 == b && a * 3 == c)
        cout << a << " " << b << " " << c << endl;
}

void permutation(int idx = 9)
{
    if (idx != 1)
    {
        for (int i = 1; i <= idx; i++)
        {
            swap(num[9 - idx], num[9 - i]);
            permutation(idx - 1);
            swap(num[9 - idx], num[9 - i]);
        }
    }
    else
    {
        check();
    }
}

int main()
{
    permutation();
}
