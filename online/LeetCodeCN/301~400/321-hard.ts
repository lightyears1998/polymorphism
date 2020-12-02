// 困难
// 模拟

// 分两个步骤解决问题，
// 第一步需要使用到单调栈：
// https://leetcode-cn.com/problems/create-maximum-number/solution/pin-jie-zui-da-shu-by-leetcode-solution/
// 第二步是写出合理的合并算法。

function maxNumber(nums1: number[], nums2: number[], k: number): number[] {
    let m = nums1.length, n = nums2.length, ans = newArray(k)

    let start = Math.max(0, k - n)
    let end = Math.min(k, m)

    for (let i = start; i <= end; ++i) {
        let max1 = maxSequence(nums1, i)
        let max2 = maxSequence(nums2, k - i)

        let ret = merge(max1, max2)
        if (compare(ret, ans) > 0) {
            ans = ret
        }
    }

    return ans
};

function newArray(size: number): number[] {
    const ret = []
    for (let i = 0; i < size; ++i) {
        ret.push(0)
    }
    return ret
}

function maxSequence(nums: number[], len: number): number[] {
    const ret = []

    let remain = nums.length
    for (const num of nums) {
        if (len - ret.length === remain) {
            ret.push(num)
            --remain
            continue
        }

        while (ret.length > 0 && ret[ret.length - 1] < num && remain >= len - ret.length + 1) {
            ret.pop()
        }

        if (len - ret.length > 0) {
            ret.push(num)
        }
        --remain
    }

    return ret
}

function merge(nums1: number[], nums2: number[]): number[] {
    const ret = []

    while (nums1.length > 0 && nums2.length > 0) {
        const num1 = nums1[0]
        const num2 = nums2[0]

        let decided = false
        for (let i = 0; i < Math.min(nums1.length, nums2.length); ++i) {
            if (nums1[i] !== nums2[i]) {
                if (nums1[i] > nums2[i]) {
                    nums1.shift()
                    ret.push(num1)
                } else if (nums1[i] < nums2[i]) {
                    nums2.shift()
                    ret.push(num2)
                }

                decided = true
                break
            }
        }

        if (!decided) {
            if (nums1.length > nums2.length) {
                nums1.shift()
                ret.push(num1)
            } else {
                nums2.shift()
                ret.push(num2)
            }
        }
    }

    if (nums1.length > 0) {
        ret.push(...nums1)
    }

    if (nums2.length > 0) {
        ret.push(...nums2)
    }

    return ret
}

function compare(nums1: number[], nums2: number[]): number {
    for (let i = 0; i < nums1.length; ++i) {
        if (nums1[i] !== nums2[i]) {
            return nums1[i] - nums2[i]
        }
    }
    return 0
}
