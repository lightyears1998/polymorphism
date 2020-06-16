// 爬楼梯 https://leetcode-cn.com/problems/climbing-stairs/
// DP

var dp = map[int]int {
    1: 1,
    2: 2,
}

func climbStairs(n int) int {
    ans, cached := dp[n]
    if !cached {
        ans = climbStairs(n-1) + climbStairs(n-2)
        dp[n] = ans
    }
    return ans
}
