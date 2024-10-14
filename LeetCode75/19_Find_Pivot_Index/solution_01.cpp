class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len = nums.size();
        for (int i = 1; i < len; i++) {
            nums[i] += nums[i - 1];
        }
        int pivotIndex = -1;
        for (int i = 0; i < len; i++) {
            int left = ((i) ? nums[i - 1] : 0);
            int right = nums[len - 1] - nums[i];
            if (left == right) {
                pivotIndex = i;
                break;
            }
        }
        return pivotIndex;
    }
};
