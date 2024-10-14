class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; i++) {
            int val = i;
            while (val > 0) {
                // val & (val-1) remove the right most '1'
                val = (val & (val - 1));
                ans[i]++;
            }
        }
        return ans;
    }
};