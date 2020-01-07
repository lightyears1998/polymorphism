#include <iostream>
using namespace std;

int y;

int main()
{
    cin >> y;
    if (!(y % 100)) {
        if (!(y % 400)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    } else {
        if (y % 4) {
            cout << "no" << endl;
        } else {
            cout << "yes" << endl;
        }
    }
}
