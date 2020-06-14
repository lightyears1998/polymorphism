// 转变数组后最接近目标的数组和 https://leetcode-cn.com/problems/sum-of-mutated-array-closest-to-target/
// 单调（两个相邻区间的单调性）、二分

// 也可以考虑从数学性质入手，从数组的平均值开始枚举。

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int len = arr.size();
        vector<int> prefix(len + 1);

        sort(arr.begin(), arr.end());
        for (int i = 0; i < len; ++i) {
            prefix[i+1] = prefix[i] + arr[i];
        }

        auto getSum = [&](int value) {
            int upper_pos = upper_bound(arr.begin(), arr.end(), value) - arr.begin();
            return prefix[upper_pos] + (len - upper_pos) * value;
        };

        int left = 0, right = arr[len-1];
        int leftSum = getSum(left), rightSum = getSum(right);
        while (left < right) {
            int mid = (left + right) / 2;
            int midSum = getSum(mid);

            if (mid == left) {
                break;
            }
            else if (midSum >= target) {
                right = mid - 1;
                rightSum = getSum(rightSum);
            } else {
                left = mid;
                leftSum = midSum;
            }
        }

        return abs(getSum(left+1) - target) < abs(getSum(left) - target)
            ? left + 1
            : left;
    }
};
