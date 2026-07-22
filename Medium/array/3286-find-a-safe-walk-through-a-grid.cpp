// 3286. Find a Safe Walk Through a Grid
// Difficulty: Medium
// Topics: Array, Breadth-First Search, Graph Theory, Heap (Priority Queue), Matrix, Shortest Path
// Link: https://leetcode.com/problems/find-a-safe-walk-through-a-grid/

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<tuple<int, int, int>> q;

        dist[0][0] = grid[0][0];
        q.push_front({grid[0][0], 0, 0});

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (!q.empty()) {
            auto [d, x, y] = q.front();
            q.pop_front();

            if (d != dist[x][y]) continue;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;

                if (d + grid[nx][ny] >= dist[nx][ny])
                    continue;

                if (grid[nx][ny] == 0) {
                    dist[nx][ny] = d;
                    q.push_front({d, nx, ny});
                } else {
                    dist[nx][ny] = d + 1;
                    q.push_back({d + 1, nx, ny});
                }
            }
        }

        return dist[m - 1][n - 1] < health;
    }
};