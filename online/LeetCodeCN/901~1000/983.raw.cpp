// 最低票价 https://leetcode-cn.com/problems/minimum-cost-for-tickets/
// 无优化DP

class Solution {
    unordered_set<int> days;
    vector<int> costs;
    int memo[366];

    template <typename T>
    T min(T a, T b) {
        return a < b ? a : b;
    }

    template <typename T, typename... Ts>
    T min(T a, Ts... b) {
        return min(a, min(b...));
    }

    int dp(int i) {
        if (i < 1) {
            return 0;
        }

        if (memo[i]) {
            return memo[i];
        }

        if (!days.count(i)) {
            memo[i] = dp(i-1);
        } else {
            memo[i] = min(dp(i-1) + costs[0], dp(i-7) + costs[1], dp(i-30) + costs[2]);
        }

        return memo[i];
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        for (const auto &d: days) {
            this->days.insert(d);
        }
        this->costs = costs;
        memset(memo, sizeof(memo), 0);

        return dp(*days.rbegin());
    }
};
