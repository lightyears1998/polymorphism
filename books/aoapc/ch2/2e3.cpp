#include <iostream>
using namespace std;

int n, t;

int main()
{
    cin >> n;
    t = 1;
    while (t <= n)
    {
        int space = t - 1;
        while (true)
        {
            if (!space--) break;
            cout << " ";
        }
        int star = 2 * n - 2 * (t - 1) - 1;
        while (true)
        {
            if (!star--) break;
            cout << "#";
        }
        cout << endl;
        t++;
    }
}
