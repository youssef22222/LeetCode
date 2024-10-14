class Solution {
public:
    int tribonacci(int n) {
        vector<int> tribo(n + 1);
        for (int i = 0; i <= n; i++) {
            if (i <= 2) {
                tribo[i] = (i + 1) / 2;
            } else {
                tribo[i] = tribo[i - 1] + tribo[i - 2] + tribo[i - 3];
            }
        }
        return tribo[n];
    }
};