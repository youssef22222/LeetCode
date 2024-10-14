class Solution {
public:
    void getCombinations(int k,int n,int last,vector<int>curCombination,vector<vector<int>>& combinations){
        if(k==0){
           if(n==0){
            combinations.push_back(curCombination);
           }
           return;
        }
        for(int i=last+1;i<=9;i++){
            if(i<=n){
                curCombination.push_back(i);
                getCombinations(k-1,n-i,i,curCombination,combinations);
                curCombination.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>combinations;
        getCombinations(k,n,0,{},combinations);
        return combinations;
    }
};