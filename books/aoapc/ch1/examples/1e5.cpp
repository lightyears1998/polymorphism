#include <iostream>
using namespace std;

int n;

int main()
{
    cin >> n;
    cout.flags(cout.fixed);
    cout.precision(2);
    if (n * 95 >= 300)
    {
        cout << (double)n * 95 * 0.85 << endl;
    } else {
        // 注意保留两位小数 (double)n
        cout << (double)n * 95 << endl;
    }
}
