// 祖玛游戏
// https://leetcode-cn.com/problems/zuma-game/
// 困难

// 搜索剪枝记忆化
// 其实没有那么难
// 小心： "RRWWRRBBRR" "WB" 是可行的（将 W 放在最后一个 R 之前）

// 这可能是一个糟糕的解决方案。
// 需要加上 const 和引用限定符号和移动语义来勉强使得算法的速度达到要求。


class Solution {
private:
    unordered_map<string, int> mp;

public:
    string remove(const string &board) const {
        int i = 0;
        for (int j = 1; j <= board.size(); ++j) {
            if (j == board.size() || board[i] != board[j]) {
                if (j - i >= 3) {
                    return remove(move(board.substr(0, i) + board.substr(j)));
                }
                i = j;
            }
        }
        return board;
    }

    int dfs(const string &board, const string &hand) {
        if (mp.count(board + ',' + hand)) {
            return mp[board + ',' + hand];
        }

        if (board.size() == 0) {
            mp[board + ',' + hand] = hand.size();
            return hand.size();
        }
        if (hand.size() == 0)  {
            mp[board + ',' + hand] = -1;
            return -1;
        }

        int ret = -1;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < hand.size(); ++j) {
                ret = max(
                    ret, dfs(
                        remove(
                            move(board.substr(0, i) + hand[j] + board.substr(i))),
                            move(hand.substr(0, j) + hand.substr(j+1)
                        )
                    )
                );
            }
        }

        mp[board + ',' + hand] = ret;
        return ret;
    }

    int findMinStep(string board, string hand) {
        sort(hand.begin(), hand.end());
        int ans = hand.size() - dfs(board, hand);
        return ans <= hand.size() ? ans : -1;
    }
};
