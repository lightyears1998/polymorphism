// 除自身以外的数组的乘积 https://leetcode-cn.com/problems/product-of-array-except-self/

// 区间查询
// 不使用线段树，因为被查询的区间序列具有简单的线性递推性质。


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size(), product;

        vector<int> ans(length, 1);

        product = 1;
        for (int i = 0; i < length; ++i) {
            ans[i] *= product;
            product *= nums[i];
        }
        product = 1;
        for (int i = length - 1; i >= 0; --i) {
            ans[i] *= product;
            product *= nums[i];
        }

        return ans;
    }
};
