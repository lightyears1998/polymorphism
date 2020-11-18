// 283. 移动零
// https://leetcode-cn.com/problems/move-zeroes/

// 正解：数组双指针

/**
 Do not return anything, modify nums in-place instead.
 */
function moveZeroes(nums: number[]): void {
    let n = nums.length
    for (let i = 0, j = 0; j < n; ++j) {
        if (nums[j]) {
            if (i !== j) {
                [nums[i], nums[j]] = [nums[j], nums[i]]
            }
            ++i
        }
    }
};
