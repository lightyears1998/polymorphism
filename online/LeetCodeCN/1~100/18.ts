// https://leetcode-cn.com/problems/4sum/
// 四数之和

// 需要注意的是对“去重”的处理。

function fourSum(nums: number[], target: number): number[][] {
    nums.sort((a, b) => {
        return a - b
    })

    const ans = []

    // 在数组有序的前提下，在本层循环中，如果当前的元素与上次的元素相同，
    // 则跳过当前元素，可以有效去重。
    for (let i = 0; i < nums.length; ++i) {
        if (nums[i] === nums[i-1]) {
            continue
        }

        let lastNumJ = undefined
        for (let j = i + 1; j < nums.length; ++j) {
            if (nums[j] === lastNumJ) {
                continue
            }
            lastNumJ = nums[j]

            let lastNumM = undefined, lastNumN = undefined
            for (let m = j + 1, n = nums.length - 1; m < n; ) {
                lastNumN = nums[n], lastNumM = nums[m]
                const sum = nums[i] + nums[j] + nums[m] + nums[n]
                if (sum === target) {
                    ans.push([nums[i], nums[j], nums[m], nums[n]])

                    do {
                        --n
                    } while (lastNumN === nums[n])
                    do {
                        ++m
                    } while (lastNumM === nums[m])
                    continue
                } else if (sum > target) {
                    do {
                        --n
                    } while (lastNumN === nums[n])
                    continue
                } else if (sum < target) {
                    do {
                        ++m
                    } while (lastNumM === nums[m])
                    continue
                }
            }
        }
    }

    return ans
};
