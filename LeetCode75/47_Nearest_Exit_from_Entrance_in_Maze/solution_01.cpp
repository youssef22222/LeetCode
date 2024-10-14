class Solution {
    int mx = 10000;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

public:
    bool vaild(vector<vector<char>>& maze, vector<int> entrance,
               vector<vector<bool>>& vis, int& n, int& m) {
        if (entrance[0] < 0 || entrance[0] >= n || entrance[1] < 0 ||
            entrance[1] >= m) {
            return false;
        }
        if (vis[entrance[0]][entrance[1]]) {
            return false;
        }
        if (maze[entrance[0]][entrance[1]] == '+') {
            return false;
        }
        return true;
    }
    int bfs(vector<vector<char>>& maze, vector<int>& entrance,
            vector<vector<bool>>& vis, int& n, int& m) {
        vis[entrance[0]][entrance[1]] = true;
        queue<pair<vector<int>, int>> cell;
        cell.push({entrance, 0});
        while (!cell.empty()) {
            vector<int> entrance = cell.front().first;
            int depth = cell.front().second;
            cell.pop();
            if ((entrance[0] == 0 || entrance[0] == n - 1 || entrance[1] == 0 ||
                 entrance[1] == m - 1) &&
                depth) {
                return depth;
            }
            for (int i = 0; i < 4; i++) {
                if (vaild(maze, {entrance[0] + dx[i], entrance[1] + dy[i]}, vis,
                          n, m)) {
                    cell.push({{entrance[0] + dx[i], entrance[1] + dy[i]},
                               depth + 1});
                    vis[entrance[0] + dx[i]][entrance[1] + dy[i]] = true;
                }
            }
        }

        return -1;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        return bfs(maze, entrance, vis, n, m);
    }
};