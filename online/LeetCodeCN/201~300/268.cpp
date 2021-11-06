// 丢失的数字
// https://leetcode-cn.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(-1);
        for (int i = 0; i <= n; ++i) {
            while (nums[i] != i && nums[i] != -1) {
                swap(nums[i], nums[nums[i]]);
            }
        }
        for (int i = 0; i <= n; ++i) {
            if (nums[i] == -1) {
                return i;
            }
        }
        return -1;
    }
};
