class Solution {
public:
    bool isValid(int len, int k, vector<int>& nums) {
        int zeroCounter = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= len && zeroCounter <= k) {
                return true;
            } else {
                if (i >= len) {
                    zeroCounter -= (nums[i - len] == 0);
                }
                zeroCounter += (nums[i] == 0);
            }
        }
        return (zeroCounter <= k);
    }
    int longestOnes(vector<int>& nums, int k) {
        int len = nums.size();
        int left = 0;
        int right = len;
        int ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (isValid(mid, k, nums)) {
                left = mid + 1;
                ans = max(ans, mid);
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};