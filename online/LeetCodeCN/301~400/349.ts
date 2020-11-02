// 349. 两个数组的交集
// https://leetcode-cn.com/problems/intersection-of-two-arrays/

// 可以使用集合来优化查询的时间。

function intersection(nums1: number[], nums2: number[]): number[] {
    const numSet1 = new Set<number>(), numSet2 = new Set<number>()
    for (const num of nums1) {
        numSet1.add(num)
    }
    for (const num of nums2) {
        numSet2.add(num)
    }

    const intersect: number[] = []
    const [smallerSet, biggerSet] = numSet1.size < numSet2.size ? [numSet1, numSet2] : [numSet2, numSet1]
    for (const num of smallerSet.values()) {
        if (biggerSet.has(num)) {
            intersect.push(num)
        }
    }
    return intersect
};
