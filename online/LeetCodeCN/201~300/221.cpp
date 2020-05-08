// https://leetcode-cn.com/problems/maximal-square/
// DP

// 【注意】如果下标自1开始，可减少冗余代码。

class Solution {
    template <typename T>
    T min(T a, T b) {
        return a < b ? a : b;
    }

    template <typename T, typename... Ts>
    T min(T a, Ts... b) {
        return min(a, min(b...));
    }

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rowSize = matrix.size();
        if (rowSize == 0) {
            return 0;
        }
        int colSize = matrix[0].size();
        if (colSize == 0) {
            return 0;
        }

        // dp(i, j) =def= 以(i, j)为右下角的正方形的最大边长
        // when i == 1 or j == 1:
        //   dp(i, j) = 1 if matrix(i, j) == 1 else 0
        // when matrix(i, j) == 1:
        //   dp(i, j) = min(dp(i-1, j), dp(i-1, j-1), dp(i, j-1)) + 1;
        // when matrix(i, j) == 0:
        //   dp(i, j) = 0;
        vector<vector<int>> dp(rowSize);
        for (auto &col: dp) {
            col.resize(colSize);
        }

        for (int i = 0; i < rowSize; ++i) {
            dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
        }
        for (int j = 0; j < colSize; ++j) {
            dp[0][j] = matrix[0][j] == '1' ? 1 : 0;
        }
        for (int i = 1; i < rowSize; ++i) {
            for (int j = 1; j < colSize; ++j) {
                if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans * ans;
    }
};
