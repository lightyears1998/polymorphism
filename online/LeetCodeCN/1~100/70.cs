// 爬楼梯 https://leetcode-cn.com/problems/climbing-stairs/
// DP

public class Solution {
    private Dictionary<int, int> dp = new Dictionary<int, int>();

    public Solution() {
        dp.Add(1, 1);
        dp.Add(2, 2);
    }

    public int ClimbStairs(int n) {
        int result = 0;
        if (!dp.TryGetValue(n, out result)) {
            result = ClimbStairs(n-1) + ClimbStairs(n-2);
            dp.Add(n, result);
        }
        return result;
    }
}
