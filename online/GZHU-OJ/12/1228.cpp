#include <iostream>
using namespace std;

int main()
{
    int total, num[25],ability;
    while (cin >> total)
    {
        for (int i = 0; i < total; i++) cin >> num[i];
        cin >> ability;

        int todo = 0, day = 0;
        for (int i = 0; i < total; i++)
        {
            todo += num[i];
            if (!todo) continue;

            todo -= ability;
            if (todo < 0) todo = 0;
            day++;
        }
        while (todo > 0)
        {
            todo -= ability;
            day++;
        }

        cout << day << endl;
    }
}
