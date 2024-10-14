class Solution {
public:
    int solve(int cur, vector<int>& cost, vector<int>& dp) {
        if (cur >= cost.size()) {
            return 0;
        }
        int& ret = dp[cur];
        if (ret != -1) {
            return ret;
        }
        return ret = min(solve(cur + 1, cost, dp), solve(cur + 2, cost, dp)) +
                     cost[cur];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        return min(solve(0, cost, dp), solve(1, cost, dp));
    }
};