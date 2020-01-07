#include <iostream>
using namespace std;

double f;

int main()
{
    cin >> f;
    
    cout.flags(cout.fixed);
    cout.precision(3);
    cout << 5 * (f - 32) / 9 << endl;
}
