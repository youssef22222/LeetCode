class Solution {
public:
    int solve(int cur, vector<int>& nums, vector<int>& dp) {
        if (cur >= nums.size()) {
            return 0;
        }
        int& ret = dp[cur];
        if (ret != -1) {
            return ret;
        }
        int rob = 0, skip = 0;
        rob = solve(cur + 2, nums, dp) + nums[cur];
        skip = solve(cur + 1, nums, dp);
        return ret = max(rob, skip);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(0, nums, dp);
    }
};