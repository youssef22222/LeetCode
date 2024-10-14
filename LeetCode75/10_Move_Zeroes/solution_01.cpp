class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /*
           using two pointers (left) for zeros and (right) for others numbers
        */
        int left = 0;
        int right = 0;
        int n = nums.size();
        while (right < n) {
            if (nums[left] == 0 && right < n && nums[right] != 0) {
                swap(nums[left], nums[right]);
                left++;
            } else if (nums[left] != 0) {
                left++;
            }
            right++;
        }
    }
};