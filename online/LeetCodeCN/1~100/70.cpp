// 爬楼梯 https://leetcode-cn.com/problems/climbing-stairs/
// DP

class Solution {
    unordered_map<int, int> dp;

public:
    Solution() {
        dp[1] = 1;
        dp[2] = 2;
    }

    int climbStairs(int n) {
        return dp[n] ? dp[n] : (dp[n] = climbStairs(n-1)+ climbStairs(n-2));
    }
};
