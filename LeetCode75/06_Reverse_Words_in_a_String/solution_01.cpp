class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string ans = "";
        while (ss >> word) {
            ans = word + ((ans == "") ? "" : " ") + ans;
        }
        return ans;
    }
};