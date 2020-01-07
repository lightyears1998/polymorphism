#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    // for (int i = 2; i <= 2*n; i+= 2)
    for (int i = 1; i <= n; i++)
    {
        cout << 2 * i << endl;
    }
    return 0;
}
