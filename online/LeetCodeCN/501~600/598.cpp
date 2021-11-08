// 范围求和 II
// https://leetcode-cn.com/problems/range-addition-ii/

// 初见误以为是 RMQ
// 其实条件比 RMQ 宽松，因此只是简单逻辑

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minA = m;
        int minB = n;
        for (const vector<int> &pair: ops) {
            const int &a = pair[0];
            const int &b = pair[1];
            minA = min(minA, a);
            minB = min(minB, b);
        }
        return minA * minB;
    }
};
