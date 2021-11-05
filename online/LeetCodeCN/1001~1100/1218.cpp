// 最长定差子序列
// https://leetcode-cn.com/problems/longest-arithmetic-subsequence-of-given-difference/

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int ans = 0;
        for (auto &num : arr) {
            dp[num] = dp[num - difference] + 1;
            ans = max(ans, dp[num]);
        }
        return ans;
    }
};
