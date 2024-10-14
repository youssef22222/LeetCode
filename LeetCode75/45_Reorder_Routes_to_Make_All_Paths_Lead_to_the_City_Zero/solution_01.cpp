class Solution {
public:
    int dfs(int src, vector<vector<pair<int, bool>>>& adj,
            vector<bool>& visited) {
        visited[src] = true;
        int ret = 0;
        for (auto child : adj[src]) {
            if (!visited[child.first]) {
                if (child.second) {
                    ret += dfs(child.first, adj, visited);
                } else {
                    ret += dfs(child.first, adj, visited) + 1;
                }
            }
        }
        return ret;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, bool>>> adj(n);
        for (auto connection : connections) {
            adj[connection[0]].push_back({connection[1], false});
            adj[connection[1]].push_back({connection[0], true});
        }
        vector<bool> visited(n);
        return dfs(0, adj, visited);
    }
};