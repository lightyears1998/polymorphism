#include <iostream>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int w, h; cin >> w >> h;
        cout << (w * h % 2 ? "Hussain" : "Hasan") << endl;
    }
}
