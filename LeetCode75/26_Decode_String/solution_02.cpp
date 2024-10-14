class Solution {
public:
    string decode(int& pos, string& str) { //notice int & pos
        string ret = "";
        while (pos < str.size() && str[pos] != ']') {
            if (!isdigit(str[pos])) {
                ret += str[pos++];
            } else {
                int num = 0;
                while (pos < str.size() && isdigit(str[pos])) {
                    num = num * 10 + str[pos++] - '0';
                }
                pos++; // '['
                string inside = decode(pos, str);
                pos++; // ']'
                while (num--) {
                    ret += inside;
                }
            }
        }
        return ret;
    }
    string decodeString(string s) {
        int pos = 0;
        return decode(pos, s);
    }
};