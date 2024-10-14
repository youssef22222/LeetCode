
class Solution {
public:
    int compress(vector<char>& chars) {
        int len = chars.size();
        int newLength = 0;
        int cnt = 1;
        int lastIndex = 0;
        for (int i = 1; i < len; i++) {
            if (chars[i] != chars[i - 1]) {
                newLength ++;
                chars[lastIndex++] = chars[i - 1];
                if (cnt > 1) {
                    string str = to_string(cnt);
                    for (auto ch : str) {
                        chars[lastIndex++] = ch;
                        newLength++;
                    }
                }
                cnt = 1;
            }
            else {
                cnt++;
            }
        }
        chars[lastIndex++] = chars[len - 1];
        if (cnt > 1) {
            string str = to_string(cnt);
            for (auto ch : str) {
                chars[lastIndex++] = ch;
                newLength++;
            }
        }
        newLength ++;
        return newLength;
    }
};