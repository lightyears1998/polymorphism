// 每个元音包含偶数次的最长子字符串
// https://leetcode-cn.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
// 前缀和 状态压缩

class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> pos(1 << 5, INT_MIN);
        pos[0] = -1; // Pay attention.

        int ans = 0, status = 0;
        for (int i = 0; i < s.size(); ++i) {
            switch (s[i]) {
                case 'a': status ^= 1 << 0; break;
                case 'e': status ^= 1 << 1; break;
                case 'i': status ^= 1 << 2; break;
                case 'o': status ^= 1 << 3; break;
                case 'u': status ^= 1 << 4; break;
            }

            if (pos[status] != INT_MIN) {
                ans = max(ans, i - pos[status]);
            } else {
                pos[status] = i;
            }
        }

        return ans;
    }
};
