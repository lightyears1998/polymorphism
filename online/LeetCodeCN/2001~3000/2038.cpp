class Solution {
public:
    bool winnerOfGame(string colors) {
        int op[2] = { 0 };

        char prev = ' '; int cnt = 0;
        for (auto ch : colors) {
            if (ch != prev) {
                cnt = 1;
                prev = ch;
            } else {
                ++cnt;
                if (cnt >= 3) {
                    op[ch - 'A']++;
                }
            }
        }

        return op[0] > op[1];
    }
};
