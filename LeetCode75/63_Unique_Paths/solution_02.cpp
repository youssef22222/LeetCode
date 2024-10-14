class Solution {
public:
    int pascal(int m, int n) {
        vector<vector<unsigned long long>> pascalArray(m, vector<unsigned long long>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < min(n, i + 1); j++) {
                if (i == 0 || j == 0 || i == j) {
                    pascalArray[i][j] = 1;
                }
                else {
                    pascalArray[i][j] +=
                        pascalArray[i - 1][j] + pascalArray[i - 1][j - 1];
                }
            }
        }
        return pascalArray[m - 1][n - 1];
    }
    int uniquePaths(int m, int n) {
        // solve with combinations formula
        // number of paths = (n+m-1)C(n) or  (n+m-1)C(m)
        return pascal(m + n - 1, n);
        //or return pascal(m + n - 1, m);
    }
};