// https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/
// 经典贪心

// 题解：https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/solution/yong-zui-shao-shu-liang-de-jian-yin-bao-qi-qiu-1-2/

function findMinArrowShots(points: number[][]): number {
    if (points.length === 0) {
        return 0
    }

    points.sort((a, b) => {
        if (a[1] !== b[1]) {
            return a[1] - b[1]
        }
        return a[0] - b[0]
    })

    let ans = 1, pos = points[0][1]
    for (let i = 0; i < points.length; ++i) {
        if (points[i][0] > pos) {
            ++ans
            pos = points[i][1]
        }
    }

    return ans
};
