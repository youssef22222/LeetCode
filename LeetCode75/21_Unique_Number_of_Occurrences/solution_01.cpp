class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> occurencesMp, uniqueMp;
        for (int i = 0; i < arr.size(); i++) {
            occurencesMp[arr[i]]++;
        }
        for (auto it : occurencesMp) {
            uniqueMp[it.second]++;
            if (uniqueMp[it.second] > 1) {
                return false;
            }
        }
        return true;
    }
};