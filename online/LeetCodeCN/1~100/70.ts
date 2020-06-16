let dp = new Map<number, number>([[1, 1], [2, 2]]);

function climbStairs(n: number): number {
    let ans = dp.get(n);

    if (!ans) {
        ans = climbStairs(n-1) + climbStairs(n-2);
        dp.set(n, ans);
    }

    return ans;
};
