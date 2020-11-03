// 941. 有效的山脉数组
// https://leetcode-cn.com/problems/valid-mountain-array/

// 简单判定

// 这方法虽然不工整，但效率却不低。
// 不过，使用 JS 这种语言，还是追求一下工整比较好。
function validMountainArray(A: number[]): boolean {
    if (A.length < 3) {
        return false
    }

    if (A[1] <= A[0]) {
        return false
    }

    let i = 2
    while (i < A.length - 1) {
        if (A[i] <= A[i-1]) {
            break
        }
        ++i
    }

    if (A[i] === A[i-1]) {
        return false
    }

    while (i < A.length) {
        if (A[i] >= A[i-1]) {
            return false
        }
        ++i
    }

    return true
};
