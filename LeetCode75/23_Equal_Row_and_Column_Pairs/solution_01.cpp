class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int len = grid.size();
        grid.size();
        int counter = 0;
        for (int i = 0; i < len; i++) {
            vector<int> column;
            for (int j = 0; j < len; j++) {
                column.push_back(grid[j][i]);
            }
            for (int j = 0; j < len; j++) {
                counter += (column == grid[j]);
            }
        }
        return counter;
    }
};