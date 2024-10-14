class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest = max(gain[0], 0);
        for (int i = 1; i < gain.size(); i++) {
            gain[i] += gain[i - 1];
            highest = max(highest, gain[i]);
        }
        return highest;
    }
};
