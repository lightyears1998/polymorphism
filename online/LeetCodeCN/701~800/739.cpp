// 每日温度 https://leetcode-cn.com/problems/daily-temperatures/
// 模拟 暴力

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int len = T.size();
        vector<int> next(100 + 1, INT_MAX);
        vector<int> ans(len, INT_MAX);

        for (int i = len - 1; i >= 0; --i) {
            next[T[i]] = i;
            for (int j = T[i] + 1; j <= 100; ++j) {
                if (next[j] != INT_MAX) {
                    ans[i] = min(next[j] - i, ans[i]);
                }
            }
            if (ans[i] == INT_MAX) {
                ans[i] = 0;
            }
        }

        return ans;
    }
};
