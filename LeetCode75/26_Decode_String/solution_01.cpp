class Solution {
public:
    string repeatString(string str, int times) {
        string repeatedString = "";
        for (int i = 0; i < times; i++) {
            repeatedString += str;
        }
        return repeatedString;
    }
    string decodeString(string s) {
        stack<int> numSt;
        stack<string> wordSt;
        int num = 0;
        string word = "";
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + s[i] - '0';
            } else if (isalpha(s[i])) {
                word += s[i];
            } else if (s[i] == '[') {
                wordSt.push(word);
                word = "";
                numSt.push(num);
                num = 0;
            } else { // s[i]=']'
                num = numSt.top();
                numSt.pop();
                word = repeatString(word, num);
                word = wordSt.top() + word;
                wordSt.pop();
                num = 0;
            }
        }
        return word;
    }
};