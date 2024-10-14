class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singleNum = 0;
        for (int i = 0; i < nums.size(); i++) {
            //  X^0=X  &&&  X^X=0
            singleNum ^= nums[i];
        }
        return singleNum;
    }
};