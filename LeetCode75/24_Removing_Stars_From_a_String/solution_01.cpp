class Solution {
public:
    string removeStars(string s) {
        int len=s.size();
        vector<bool>isRemoved(len);
        int starsCounter=0;
        for(int i=len-1;i>=0;i--){
           if(s[i]=='*')
           {
            starsCounter++;
            isRemoved[i]=true;
           }else if(starsCounter){
            starsCounter--;
            isRemoved[i]=true;
           }
        }
        string sAfterStarsRemoved="";
        for(int i=0;i<len;i++){
            if(!isRemoved[i]){
                sAfterStarsRemoved+=s[i];
            }
        }
        return sAfterStarsRemoved;
    }
};