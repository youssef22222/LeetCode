class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        /*
        adding 1000 to the values to avoid negative values
        */
        vector<int> freqNums1(2005), freqNums2(2005);
        int shift = 1000;
        for (int i = 0; i < nums1.size(); i++) {
            freqNums1[nums1[i] + shift]++;
        }
        for (int i = 0; i < nums2.size(); i++) {
            freqNums2[nums2[i] + shift]++;
        }
        vector<int> ans1, ans2;
        for (int i = 0; i < nums1.size(); i++) {
            if (!freqNums2[nums1[i] + shift] && freqNums1[nums1[i] + shift]) {
                ans1.push_back(nums1[i]);
                freqNums1[nums1[i] + shift] = 0;
            }
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (!freqNums1[nums2[i] + shift] && freqNums2[nums2[i] + shift]) {
                ans2.push_back(nums2[i]);
                freqNums2[nums2[i] + shift] = 0;
            }
        }
        return {ans1, ans2};
    }
};