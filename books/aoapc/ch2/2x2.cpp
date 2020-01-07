#include <iostream>
using namespace std;

int main()
{
    double i;
    for (i = 0; i != 10; i += 0.1)
    {
        cout << i << endl;
        if (i > 10.2) break;
    }
    return 0;
}
