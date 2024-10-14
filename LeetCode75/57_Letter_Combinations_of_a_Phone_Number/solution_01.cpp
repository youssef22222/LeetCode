class Solution {
public:
    void getCombinations(int curPos, string curStr, string& digits,
                         vector<string>& combinations,
                         vector<string>& charsOnDigit) {
        if (curPos == digits.size()) {
            combinations.push_back(curStr);
            return;
        }
        string curChars = charsOnDigit[digits[curPos] - '2'];
        for (auto ch : curChars) {
            getCombinations(curPos + 1, curStr + ch, digits, combinations,
                            charsOnDigit);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> charsOnDigit = {"abc", "def",  "ghi", "jkl",
                                       "mno", "pqrs", "tuv", "wxyz"};
        vector<string> combinations;
        if (digits == "") {
            return combinations;
        }
        getCombinations(0, "", digits, combinations, charsOnDigit);
        return combinations;
    }
};