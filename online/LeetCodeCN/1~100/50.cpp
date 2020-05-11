// Pow(x, n)
// https://leetcode-cn.com/problems/powx-n/
// 快速幂

class Solution {
public:
    double myPow(double x, long long n) {
        if (n < 0) {
            // Incorrect when use `int` type and input is -2147483648.
            //! return 1 / myPow(x, -n);
            return 1 / myPow(x, -n);
        }

        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }

        double half = myPow(x, n/2);
        double extra = n % 2 ? x : 1;
        return half * half * extra;
    }
};
