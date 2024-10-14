class Solution {
public:
    double bfs(string src, string dest,
               map<string, vector<pair<string, double>>>& adj) {
        map<string, bool> visited;
        queue<pair<string, double>> equation;
        visited[src] = true;
        equation.push({src, 1.0});
        while (!equation.empty()) {
            pair<string, double> cur = equation.front();
            if (cur.first == dest) {
                return cur.second;
            }
            equation.pop();
            for (auto node : adj[cur.first]) {
                if (!visited[node.first]) {
                    equation.push({node.first, cur.second * node.second});
                    visited[node.first] = true;
                }
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        map<string, vector<pair<string, double>>> adj;
        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            adj[u].push_back({v, values[i]});
            adj[v].push_back({u, 1 / values[i]});
        }
        int len = queries.size();
        vector<double> answer(len, -1.0);
        for (int i = 0; i < len; i++) {
            string src = queries[i][0];
            string dest = queries[i][1];
            if (adj[src].size() > 0 && adj[dest].size() > 0) {
                answer[i] = bfs(src, dest, adj);
            }
        }
        return answer;
    }
};