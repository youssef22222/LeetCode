class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int numI = INT_MAX;
        int numJ = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= numI) {
                numI = nums[i];
            } else if (nums[i] <= numJ) {
                numJ = nums[i];
            } else {
                return true;
            }
        }
        return false;
    }
};
