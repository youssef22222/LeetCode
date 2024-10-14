class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        int n = spells.size();
        int m = potions.size();
        int mxNum = 1e5 + 1;
        vector<int> pairs(n);
        vector<int> suffixFreq(mxNum);
        for (int i = 0; i < m; i++) {
            suffixFreq[potions[i]]++;
        }
        for (int i = mxNum - 2; i >= 0; i--) {
            suffixFreq[i] += suffixFreq[i + 1];
        }
        for (int i = 0; i < n; i++) {
            long long mnVal = success / spells[i] + (success % spells[i] != 0);
            pairs[i] = ((mnVal > mxNum - 1) ? 0 : suffixFreq[mnVal]);
        }
        return pairs;
    }
};