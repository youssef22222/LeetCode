class Solution {
public:
    void dfs(int src, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[src] = true;
        for (int child = 0; child < isConnected[src].size(); child++) {
            if (!visited[child] && isConnected[src][child]) {
                dfs(child, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n);
        int connectedComponentsCount = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                connectedComponentsCount++;
                dfs(i, isConnected, visited);
            }
        }
        return connectedComponentsCount;
    }
};