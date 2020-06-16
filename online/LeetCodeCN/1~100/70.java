// 爬楼梯 https://leetcode-cn.com/problems/climbing-stairs/
// DP

class Solution {
    HashMap<Integer, Integer> dp;

    public Solution() {
        dp = new HashMap<Integer, Integer>();
        dp.put(1, 1);
        dp.put(2, 2);
    }

    public int climbStairs(int n) {
        if (dp.containsKey(n)) {
            return dp.get(n);
        }

        int result = climbStairs(n-1) + climbStairs(n-2);
        dp.put(n, result);
        return result;
    }
}
