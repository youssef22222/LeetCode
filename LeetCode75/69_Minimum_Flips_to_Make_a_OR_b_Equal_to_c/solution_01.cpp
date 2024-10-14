class Solution {
public:
    int minFlips(int a, int b, int c) {
        int counter = 0;
        while (max(a, max(b, c))) {
            if (((a | b) & 1) != (c & 1)) {
                counter += ((c & 1) ? 1 : 1 + (a & b & 1));
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return counter;
    }
};