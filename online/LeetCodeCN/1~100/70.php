class Solution {
    private $dp;

    public function __construct() {
        $this->dp = [1 => 1, 2 => 2];
    }

    /**
     * @param Integer $n
     * @return Integer
     */
    public function climbStairs($n) {
        $ans = $this->dp[$n];

        if ($ans == 0) {
            $ans = $this->dp[$n] = $this->climbStairs($n-1) + $this->climbStairs($n-2);
        }

        return $ans;
    }
}
