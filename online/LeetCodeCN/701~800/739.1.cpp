// 每日温度 https://leetcode-cn.com/problems/daily-temperatures/
// 数学 单调性质 单调栈

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int len = T.size();
        vector<int> ans(len);
        stack<int> stk;

        for (int i = 0; i < len; ++i) {
            while (!stk.empty() && T[i] > T[stk.top()]) {
                ans[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }

        return ans;
    }
};
