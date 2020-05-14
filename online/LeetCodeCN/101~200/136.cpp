// 只出现一次的数字
// https://leetcode-cn.com/problems/single-number/
// 异或

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (const int &num : nums) {
            res ^= num;
        }
        return res;
    }
};
