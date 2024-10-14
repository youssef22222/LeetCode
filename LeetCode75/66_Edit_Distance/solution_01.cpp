class Solution {
    const int OO = 0x3f3f3f3f;

public:
    int editDistance(int pos1, int pos2, string& word1, string& word2, vector<vector<int>>& dp) {
        if (pos1 == word1.size()) {
            return word2.size() - pos2;
        } else if (pos2 == word2.size()) {
            return word1.size() - pos1;
        }
        int& ret = dp[pos1][pos2];
        if (ret != OO) {
            return ret;
        }
        if (word1[pos1] == word2[pos2]) {
            ret = editDistance(pos1 + 1, pos2 + 1, word1, word2, dp);
        } else {
            ret = min(ret, editDistance(pos1 + 1, pos2, word1, word2, dp) + 1); // insert
            ret = min(ret, editDistance(pos1 + 1, pos2 + 1, word1, word2, dp) + 1); // replace
            ret = min(ret, editDistance(pos1, pos2 + 1, word1, word2, dp) + 1); // delete
        }
        return ret;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), OO));
        if (word1 == "") {
            return word2.size();
        }
        return editDistance(0, 0, word1, word2, dp);
    }
};