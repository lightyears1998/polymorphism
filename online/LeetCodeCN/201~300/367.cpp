// 完全平方数
// https://leetcode-cn.com/problems/valid-perfect-square

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long a = 1;
        long long b = 1LL<<16;
        while (a <= b) {
            long long m = (a + b) / 2;
            long long rst = m * m;
            if (rst == num) {
                return true;
            } else if (rst < num) {
                a = m + 1;
            } else {
                b = m - 1;
            }
        }
        return false;
    }
};
