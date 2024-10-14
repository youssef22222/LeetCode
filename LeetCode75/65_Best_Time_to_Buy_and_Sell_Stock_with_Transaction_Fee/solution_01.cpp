class Solution {
    int OO = 0xf3f3f3f3;

public:
    long long solve(int cur, bool canBuy, vector<int>& prices, int fee,
                    vector<vector<long long>>& dp) {
        if (cur == prices.size()) {
            return 0;
        }
        long long& ret = dp[canBuy][cur];
        if (ret != -1) {
            return ret;
        }
        if (canBuy) {
            ret = max(ret, solve(cur + 1, false, prices, fee, dp) -
                               prices[cur] - fee);
        } else {
            ret = max(ret, solve(cur + 1, true, prices, fee, dp) + prices[cur]);
        }
        ret = max(ret, solve(cur + 1, canBuy, prices, fee, dp));
        return ret;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<long long>> dp =
            vector<vector<long long>>(2, vector<long long>(prices.size(), -1));
        return solve(0, 1, prices, fee, dp);
    }
};