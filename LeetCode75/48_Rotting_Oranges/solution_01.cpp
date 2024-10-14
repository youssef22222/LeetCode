class Solution {
    int const OO = 1e9;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

public:
    bool isValid(pair<int, int> orange, vector<vector<int>>& grid,
                 vector<vector<bool>>& visited, int n, int m) {
        if (orange.first < 0 || orange.first >= n || orange.second < 0 ||
            orange.second >= m) {
            return false;
        }
        if (visited[orange.first][orange.second]) {
            return false;
        }
        if (grid[orange.first][orange.second] == 0) {
            return false;
        }
        return true;
    }
    int bfs(vector<pair<int, int>>& rotten, vector<vector<int>>& grid, int n,
            int m) {

        vector<vector<int>> time(n, vector<int>(m, OO));
        vector<vector<bool>> visited(n, vector<bool>(m));
        queue<pair<int, int>> q;
        for (auto orange : rotten) {
            q.push(orange);
            time[orange.first][orange.second] = 0;
            visited[orange.first][orange.second] = true;
        }
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                if (isValid({cur.first + dx[i], cur.second + dy[i]}, grid,
                            visited, n, m)) {
                    q.push({cur.first + dx[i], cur.second + dy[i]});
                    time[cur.first + dx[i]][cur.second + dy[i]] =
                        time[cur.first][cur.second] + 1;
                    visited[cur.first + dx[i]][cur.second + dy[i]] = true;
                }
            }
        }
        int mnTime = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    mnTime = max(mnTime, time[i][j]);
                }
            }
        }
        return ((mnTime == OO) ? -1 : mnTime);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int, int>> rotten;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    rotten.push_back({i, j});
                }
            }
        }
        return bfs(rotten, grid, n, m);
    }
};