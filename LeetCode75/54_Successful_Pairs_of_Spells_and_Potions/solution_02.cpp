//O(n) solution
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> pairs(n);
        int mxNum = 1e5 + 1;
        vector<int> counter(mxNum);
        int cur = mxNum - 1;
        int pos = m - 1;
        int values = 0;
        for (int i = mxNum - 1; i >= 0; i--) {
            bool check = false;
            if (pos >= 0 && i == potions[pos]) {
                pos--;
                values++;
                check = true; // to work with the same values
            }
            counter[i] = values;
            i += check;
        }
        for (int i = 0; i < n; i++) {
            long long mnVal = success / spells[i] + (success % spells[i] != 0);
            pairs[i] = ((mnVal > mxNum - 1) ? 0 : counter[mnVal]);
        }
        return pairs;
    }
};