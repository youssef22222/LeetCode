class Solution {
public:
    int binarySearch(int left, int right, vector<int>& nums) {
        if (left == right) {
            return left;
        }
        int mid = (left + right) / 2;
        if (nums[mid] < nums[mid + 1]) {
            return binarySearch(mid + 1, right, nums);
        } else {
            return binarySearch(left, mid, nums);
        }
    }
    int findPeakElement(vector<int>& nums) {
        return binarySearch(0, nums.size()-1, nums);
    }
};