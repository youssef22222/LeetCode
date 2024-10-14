class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len = nums.size();
        vector<int> suffix = nums;
        for (int i = len - 2; i >= 0; i--) {
            if (suffix[i] && suffix[i + 1]) {
                suffix[i] += suffix[i + 1];
            }
        }
         vector<int> prefix = nums;
        for (int i = 1; i < len; i++) {
            if (prefix[i] && prefix[i - 1]) {
                prefix[i] += prefix[i - 1];
            }
        }
        int ans = 0;
        for (int i = 0; i < len; i++) {
            ans = max(ans, ((i > 0) ? prefix[i - 1] : 0)+
                               ((i < len - 1) ? suffix[i + 1] : 0));
        }
        return ans;
    }
};