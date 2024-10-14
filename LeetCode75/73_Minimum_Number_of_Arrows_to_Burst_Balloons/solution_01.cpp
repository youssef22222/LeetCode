class Solution {
public:
    static bool sor(vector<int>& point1, vector<int>& point2) {
        if (point1[0] != point2[0]) {
            return point1[0] < point2[0];
        } else {
            return point1[1] < point2[1];
        }
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), sor);
        int counter = 1;
        int lastEnd = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] <= lastEnd) {
                lastEnd = min(lastEnd, points[i][1]);
            } else {
                counter++;
                lastEnd = points[i][1];
            }
        }
        return counter;
    }
};