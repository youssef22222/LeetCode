class Solution {
public:
    void adding(string& word, int index, string& ans) {
        while (index < word.size()) {
            ans += word[index];
            index++;
        }
    }
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int index = 0;
        while (index < word1.size() && index < word2.size()) {
            ans += word1[index];
            ans += word2[index];
            index++;
        }
        adding(word1, index, ans);
        adding(word2, index, ans);
        return ans;
    }
};