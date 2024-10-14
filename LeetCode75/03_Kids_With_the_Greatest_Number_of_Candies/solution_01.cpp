class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int len = candies.size();
        int mx = 0;
        for (int i = 0; i < len; i++) {
            mx = max(mx, candies[i]);
        }
        vector<bool> result;
        for (int i = 0; i < len; i++) {
            if (candies[i] + extraCandies >= mx) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        return result;
    }
};
