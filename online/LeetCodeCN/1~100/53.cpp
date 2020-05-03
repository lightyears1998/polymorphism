// https://leetcode-cn.com/problems/maximum-subarray/
// 动态规划方法

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mSum = INT_MIN;
        int sum = 0;

        for (unsigned i = 0; i < nums.size(); i++) {
            sum += nums[i];
            mSum = max(mSum, sum);
            sum = max(sum, 0);
        }

        return mSum;
    }
};
