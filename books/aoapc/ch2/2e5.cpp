#include <iostream>
using namespace std;

long a, b;
int c;

int main()
{
    int kase = 0;
    while (cin >> a >> b >> c && a && b && c)
    {
        cout.flags(cout.fixed);
        cout.precision(c);
        cout << "Case " << ++kase << ": " <<(double)a / b << endl;
    }
}
