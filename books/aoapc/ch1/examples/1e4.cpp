#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.1415926535;

int n;

int main()
{
    cin >> n;

    cout.flags(cout.fixed);
    cout << sin((double)n / 360 * 2 * PI) << endl;
    cout << cos((double)n / 360 * 2 * PI) << endl;
}
