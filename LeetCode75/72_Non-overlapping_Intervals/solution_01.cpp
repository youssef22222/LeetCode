class Solution {
public:
    bool static sor(vector<int> interval1, vector<int> interval2) {
        return  (interval1[0] < interval2[0]);
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int len = intervals.size();
        sort(intervals.begin(), intervals.end(), sor);
        int lastValue = -1e5;
        int nonOverlappingIntervals = 0;
        for (int i = 0; i < len; i++) {
            if (intervals[i][0] >= lastValue) {
                nonOverlappingIntervals++;
                lastValue = intervals[i][1];
            } else if (lastValue > intervals[i][1]) {
                lastValue = intervals[i][1];
            }
        }
        return len - nonOverlappingIntervals;
    }
};