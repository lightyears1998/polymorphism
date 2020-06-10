// 最长连续序列 https://leetcode-cn.com/problems/longest-consecutive-sequence/
// 模拟、哈希

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool>  mp;
        for (auto &num : nums) {
            mp[num] = true;
        }

        int ans = 0;
        for (auto &pair : mp) {
            int num = pair.first;

            // Be aware that `mp[num - 1]` inserts `(num-1, false)` to container.
            if (mp.count(num - 1)) {
                continue;
            }

            int len = 1;
            while (mp.count(num + 1)) {
                ++num, ++len;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};
