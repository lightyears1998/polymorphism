#include <iostream>
using namespace std;

signed main()
{
    int kase; cin >> kase;
    for (int i = 1; i <= kase; ++i)
    {
        cout << "Case #" << i << ": ";
        long long a, b, c; cin >> a >> b >> c;
        cout << (a+b>c ? "true" : "false") << endl;
    }
}
