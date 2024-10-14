class Solution {
    int sz = 2 * 1e4 + 2;

public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> freq(sz);
        for (auto it : nums) {
            freq[it + sz / 2]++;
        }
        int counter = 0;
        for (int i = sz - 1; i >= 0; i--) {
            counter += freq[i];
            if (counter >= k) {
                return i - sz / 2;
            }
        }
        return 0;
    }
};