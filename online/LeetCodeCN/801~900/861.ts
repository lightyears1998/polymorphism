// 861. 翻转矩阵后的得分
// 贪心
// 先变横行，再变纵行。

// 官方题解
// https://leetcode-cn.com/problems/score-after-flipping-matrix/solution/fan-zhuan-ju-zhen-hou-de-de-fen-by-leetc-cxma/

function matrixScore(A: number[][]): number {
    let ans = 0
    let m = A.length, n = A[0].length

    ans += m * Math.pow(2, n - 1)
    for (let i = 1; i < n; ++i) {
        let cnt = 0
        for (let j = 0; j < m; ++j) {
            if ((A[j][0] ^ A[j][i]) === 0) {
                ++cnt
            }
        }
        cnt = Math.max(cnt, m - cnt)
        ans += cnt * Math.pow(2, n - i - 1)
    }

    return ans
};
