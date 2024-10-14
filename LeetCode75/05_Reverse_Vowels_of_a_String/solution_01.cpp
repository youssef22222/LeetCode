class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    string reverseVowels(string s) {
        int len = s.size();
        vector<char> vowels;
        for (int i = 0; i < len; i++) {
            if (isVowel(s[i])) {
                vowels.push_back(s[i]);
            }
        }
        for (int i = 0; i < len; i++) {
            if (isVowel(s[i])) {
                s[i] = vowels.back();
                vowels.pop_back();
            }
        }
        return s;
    }
};