// https://leetcode-cn.com/problems/sort-colors/
// 颜色分类

/**
 Do not return anything, modify nums in-place instead.
 */
function sortColors(nums: number[]): void {
    let lastRed = -1, firstBlue = nums.length
    for (let i = 0; i < firstBlue; ) {
        if (nums[i] === 0) {
            [nums[lastRed + 1], nums[i]] = [nums[i], nums[lastRed + 1]]
            ++lastRed, ++i
            continue
        }

        if (nums[i] === 2) {
            [nums[firstBlue - 1], nums[i]] = [nums[i], nums[firstBlue - 1]]
            --firstBlue
            continue
        }

        ++i
    }
};
