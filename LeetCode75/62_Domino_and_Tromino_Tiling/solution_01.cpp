class Solution {
    const long long mod=1e9+7;
public:
    long long solve(int cur, int n, bool hasGap, vector<vector<long long>>& dp) {
        if (cur >= n) {
            return ((!hasGap) && (cur == n));
        }
        long long& ret = dp[hasGap][cur];
        if (ret != -1) {
            return ret;
        }
        ret=0;
        if (hasGap == 0) {
            ret += solve(cur + 2, n, 0, dp); // add two horizontal dominos
            ret += solve(cur + 1, n, 0, dp); // add one vertical domino
            ret +=2*solve(cur+1,n,1,dp); //one tromino gap up 1 for up gap and one for down gap
        } else {
            ret += solve(cur + 1, n, 1, dp); // add horizontal domino in the gap
            ret += solve(cur + 2, n, 0, dp);  // add tromino and close the gap
        }
        return ret%mod;
    }
    int numTilings(int n) {
        vector<vector<long long>> dp(2, vector<long long>(n,-1));
        return solve(0, n, 0, dp);
        return 0;
    }
};