//O(n*log(n)) solution
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> pairs(n);
        for (int i = 0; i < n; i++) {
            long long mnVal = success / spells[i] + (success % spells[i] != 0);
            int counter = lower_bound(potions.begin(), potions.end(), mnVal) - potions.begin();
            pairs[i] = m - counter;
        }
        return pairs;
    }
};