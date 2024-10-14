class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }
        double ans = INT_MIN;
        for (int i = 0; i < nums.size() - k + 1; i++) {
            int left = i;
            int right = i + k - 1;
            int result = nums[right] - ((left) ? nums[left - 1] : 0);
            ans = max((int)ans, result);
        }
        return ans / k;
    }
};