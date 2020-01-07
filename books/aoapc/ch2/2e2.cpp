#include <iostream>
using namespace std;

int a, b, c;

int main()
{
    int kase = 0;
    while (cin >> a >> b >> c)
    {
        bool flag = false;
        for (int n = 10; n <= 100; n++)
        {
            if (n % 3 == a && n % 5 == b && n % 7 == c)
            {
                cout << "Case " << ++kase << ": " << n << endl;
                flag = true;
                break;
            }
        }
        if (!flag) cout << "Case " << ++kase << ": No answer"<< endl;
    }
}
