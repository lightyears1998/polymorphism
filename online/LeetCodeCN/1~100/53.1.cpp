// https://leetcode-cn.com/problems/maximum-subarray/
// 线段树方法

class Solution {
public:
    // 区间[i, j]的状态
    struct Status {
        int lSum; // 区间内以i为左端点的最大子序列和
        int rSum; // 区间内以j为右端点的最大子序列和
        int mSum; // 区间内的最大子序列和
        int iSum; // 区间和
    };

    template<typename T>
    T max(T a, T b) {
        return a > b ? a : b;
    }

    template<typename T, typename ...Ts>
    T max(T a, Ts... args) {
        return max(a, max(args...));
    }

    Status query(const vector<int> &nums, unsigned i, unsigned j) {
        unsigned m = (i + j) / 2;

        if (i == j) {
            return Status {nums[m], nums[m], nums[m], nums[m]};
        }

        Status lStatus = query(nums, i, m);
        Status rStatus = query(nums, m + 1, j);

        int lSum = max(lStatus.lSum, lStatus.iSum + rStatus.lSum);
        int rSum = max(rStatus.rSum, rStatus.iSum + lStatus.rSum);
        int mSum = max(lStatus.mSum, rStatus.mSum, lStatus.rSum + rStatus.lSum);
        int iSum = lStatus.iSum + rStatus.iSum;
        return Status {
            lSum, rSum, mSum, iSum
        };
    }

    int maxSubArray(vector<int>& nums) {
        return query(nums, 0, nums.size()-1).mSum;
    }
};
