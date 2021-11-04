// 接雨水II

// 困难
// 优先队列

using HeightLocationPair = pair<int, int>;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        vector<vector<bool>> visited(m, vector(n, false));
        priority_queue<HeightLocationPair, vector<HeightLocationPair>, greater<HeightLocationPair>> queue;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    queue.push(make_pair(heightMap[i][j], i * n + j));
                    visited[i][j] = true;
                }
            }
        }

        int ans = 0;

        int dirs[][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!queue.empty()) {
            auto cur = queue.top();
            queue.pop();

            int x = cur.second / n;
            int y = cur.second % n;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;

                    if (heightMap[nx][ny] < cur.first) {
                        ans += cur.first - heightMap[nx][ny];
                    }
                    queue.push(make_pair(max(cur.first, heightMap[nx][ny]), nx * n + ny));
                }
            }
        }

        return ans;
    }
};
