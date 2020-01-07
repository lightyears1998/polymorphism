#include <iostream>
#include <cfloat>
using namespace std;

double a, b;

/**
 * 问题本身值得商榷。
 * 浮点型精确度取决于保留Mantissa部分的大小（即DBL_MANT_DIG的值）
 */

int main()
{
    // ,,ԾㅂԾ,, 不会写……

    cout << DBL_MIN << endl;
    cout << DBL_MAX << endl;
}
