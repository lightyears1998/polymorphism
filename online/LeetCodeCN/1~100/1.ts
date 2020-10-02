// 两数之和
// https://leetcode-cn.com/problems/two-sum/

function twoSum(nums: number[], target: number): number[] {
    const mapNum2Idx = new Map()
    for (let i = 0; i < nums.length; ++i) {
        const complement = target - nums[i]
        if (mapNum2Idx.has(complement)) {
            return [mapNum2Idx.get(complement), i]
        }
        mapNum2Idx.set(nums[i], i)
    }

    return []
};
