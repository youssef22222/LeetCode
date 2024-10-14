class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    bool divisionCheck(string& ans, string& str, int index) {
        int len = ans.size();
        while (index < str.size()) {
            if (ans != str.substr(index, len)) {
                return false;
            }
            index += len;
        }
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        string ans = "";
        /*
          the maximum common length you can get is within [0,strGcd]
        */
        int strGcd = gcd(str1.size(), str2.size());
        int index = strGcd;
        for (int i = 0; i < strGcd; i++) {
            if (str1[i] == str2[i]) {
                ans += str1[i];
            } else {
                index = i;
                break;
            }
        }
        if (index == 0) {
            return "";
        }
        if (divisionCheck(ans, str1, index) &&
            divisionCheck(ans, str2, index)) {
            return ans;
        } else {
            return "";
        }
    }
};