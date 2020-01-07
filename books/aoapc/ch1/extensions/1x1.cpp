#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int main()
{
    cout << INT_MAX << endl;
    cout << INT_MIN << endl;

    cout << endl;

    cout << (int)pow(2, sizeof(int) * 8) - 1 << endl;
    cout << (int)-pow(2, sizeof(int) * 8) << endl;
}
