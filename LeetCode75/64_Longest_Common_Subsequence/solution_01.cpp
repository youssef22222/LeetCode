class Solution {
public:
    int CLS(int pos1, int pos2, string& text1, string& text2, vector<vector<int>>& dp) {
        if (pos1 == text1.size() || pos2 == text2.size()) {
            return 0;
        }
        int& ret = dp[pos1][pos2];
        if (ret != -1) {
            return ret;
        }
        if (text1[pos1] == text2[pos2]) {
            ret = max(ret, CLS(pos1 + 1, pos2 + 1, text1, text2, dp) + 1);
        } else {
            ret = max(ret, max(CLS(pos1 + 1, pos2, text1, text2, dp),
                               CLS(pos1, pos2 + 1, text1, text2, dp)));
        }
        return ret;
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return CLS(0, 0, text1, text2, dp);
    }
};