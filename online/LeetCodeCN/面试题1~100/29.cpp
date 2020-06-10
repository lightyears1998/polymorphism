// 顺时针打印矩阵 https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/
// 模拟（按层模拟）
// 边界条件的处理是非常值得注意的难点：在必然触发的分支中，边界要“踩实”。

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int m = matrix.size();
        if (m == 0) {
            return ans;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return ans;
        }

        int left = 0, right = n-1, top = 0, bottom = m-1;
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; ++i) {
                ans.push_back(matrix[top][i]);
            }
            for (int i = top + 1; i <= bottom; ++i) {
                ans.push_back(matrix[i][right]);
            }
            if (left < right && top < bottom) {
                for (int i = right - 1; i > left; --i) {
                    ans.push_back(matrix[bottom][i]);
                }
                for (int i = bottom; i > top; --i) {
                    ans.push_back(matrix[i][left]);
                }
            }
            ++left, --right, ++top, --bottom;
        }

        return ans;
    }
};
