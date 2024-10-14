class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        int product = 1;
        int zeroCounter = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i]) {
                product *= nums[i];
            } else {
                zeroCounter++;
            }
        }
        vector<int> ans(len);
        for (int i = 0; i < len; i++) {
            if (zeroCounter) {
                if (nums[i] == 0 && zeroCounter < 2) {
                    ans[i] = product;
                }
            } else {
                ans[i] = product / nums[i];
            }
        }
        return ans;
    }
};