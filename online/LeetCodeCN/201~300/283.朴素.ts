// 283. 移动零
// https://leetcode-cn.com/problems/move-zeroes/

/**
 Do not return anything, modify nums in-place instead.
 */
function moveZeroes(nums: number[]): void {
    for (let i = 0, j = nums.length; i < j - 1; ++i) {
        if (nums[i] === 0) {
            for (let k = i; k < j - 1; ++k) {
                [nums[k], nums[k+1]] = [nums[k+1], nums[k]]
            }
            --i, --j
        }
    }
};
