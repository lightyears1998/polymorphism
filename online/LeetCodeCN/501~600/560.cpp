// 和为 k 的子数组
// https://leetcode-cn.com/problems/subarray-sum-equals-k/submissions/
// 前缀和 + 哈希计数优化


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixSum = 0;
        unordered_map<int, int> prefixSumCount;

        int ans = 0;
        prefixSumCount[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += nums[i];
            if (prefixSumCount.count(prefixSum - k)) {
                ans += prefixSumCount[prefixSum - k];

                // Comparing with a single += statement,
                // An if statement DID boost the performance.
            }
            ++prefixSumCount[prefixSum];
        }

        return ans;
    }
};
