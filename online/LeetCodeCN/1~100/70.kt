class Solution {
    var dp: MutableMap<Int, Int> = mutableMapOf(1 to 1, 2 to 2)

    fun climbStairs(n: Int): Int {
        var ans: Int? = dp[n]

        if (ans == null) {
            ans = climbStairs(n-1) + climbStairs(n-2)
            dp[n] = ans
        }

        return ans
    }
}
