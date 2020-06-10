// 新 21 点 https://leetcode-cn.com/problems/new-21-game/
// DP（反向）

// dp(i): 得分为 i 时的胜率
// 反向计算，因为正向难以计算，而终态的数量是有限的。

// 题解
// https://leetcode-cn.com/problems/new-21-game/solution/huan-you-bi-zhe-geng-jian-dan-de-ti-jie-ma-tian-ge/

class Solution {
public:
    double new21Game(int N, int K, int W) {
        double dp[K - 1 + W + 1];
        double sum = 0;

        for (int i = K - 1 + W; i >= K; --i) {
            dp[i] = i > N ? 0 : 1;
            sum += dp[i];
        }
        for (int i = K - 1; i >= 0; --i) {
            dp[i] = sum / W;
            sum += dp[i] - dp[i + W];
        }

        return dp[0];
    }
};
