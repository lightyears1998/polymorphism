#include <iostream>
using namespace std;

double a, b, c;

int main()
{
    cin >> a >> b >> c;

    cout.flags(cout.fixed);
    cout.precision(3);
    cout << (a + b + c) / 3 << endl;
}
