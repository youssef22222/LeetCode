class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    int maxVowels(string s, int k) {
        int vowelCounter = 0;
        int mx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                vowelCounter++;
            }
            if (i >= k) {
                if (isVowel(s[i - k])) {
                    vowelCounter--;
                }
            }
            mx = max(mx, vowelCounter);
        }
        return mx;
    }
};