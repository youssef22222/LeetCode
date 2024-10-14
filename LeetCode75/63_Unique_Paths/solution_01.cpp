class Solution {
public:
    int solve(int m, int n, vector<vector<int>>& dp) {
        if (m == 0 && n == 0) {
            return 1;
        }
        int& ret = dp[m][n];
        if (ret != -1) {
            return ret;
        }
        ret = 0;
        if (n) {
            ret += solve(m, n - 1, dp);
        }
        if (m) {
            ret += solve(m - 1, n, dp);
        }
        return ret;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, dp);
    }
};