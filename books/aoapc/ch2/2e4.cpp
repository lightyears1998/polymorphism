#include <iostream>
using namespace std;

long long n, m;

int main()
{
    int kase = 0;
    while (cin >> n >> m && n && m)
    {
        double sum = 0;
        while (n <= m)
        {
            sum += 1 / (double)(n * n);
            n++;
        }
        cout.flags(cout.fixed);
        cout.precision(5);
        cout << "Case " << ++kase << ": " << sum << endl;
    }
}
