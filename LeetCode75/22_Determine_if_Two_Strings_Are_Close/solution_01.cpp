class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> occurrence1(26);
        vector<int> occurrence2(26);
        for (int i = 0; i < word1.size(); i++) {
            occurrence1[word1[i] - 'a']++;
        }
        for (int i = 0; i < word2.size(); i++) {
            occurrence2[word2[i] - 'a']++;
        }
        map<int, int> mp;
        for (int i = 0; i < 26; i++) {
            // checking the same characters in occurrence
            // the times of occurrences not important
            if ((occurrence1[i] == 0 && occurrence2[i] > 0) ||
                (occurrence1[i] > 0 && occurrence2[i] == 0)) {
                return false;
            }
        }
        //"cabbba" "abbccc" occ1 [2,3,1]  occ2[1,2,3] the same numbers
        sort(occurrence1.begin(), occurrence1.end());
        sort(occurrence2.begin(), occurrence2.end());
        return occurrence1 == occurrence2;
    }
};