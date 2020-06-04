// 接雨水 https://leetcode-cn.com/problems/trapping-rain-water/
// 模拟

class Solution {
public:
    int trap(vector<int>& height) {
        int length = height.size();
        vector<int> left_fence(height.size()), right_fence(height.size());

        for (int i = 0, mx = 0; i < length; ++i) {
            mx = max(mx, height[i]);
            left_fence[i] = mx;
        }
        for (int i = length - 1, mx = 0; i >= 0; --i) {
            mx = max(mx, height[i]);
            right_fence[i] = mx;
        }

        int ans = 0;
        for (int i = 0; i < length; ++i) {
            int fence = min(left_fence[i], right_fence[i]);
            ans += max(fence - height[i], 0);
        }

        return ans;
    }
};
