class Solution {
public:
    bool isValid(int k, int h, vector<int> piles) {
        long long time = 0;
        for (auto pile : piles) {
            time += pile / k + (pile % k != 0);
        }
        return time <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 1e9;
        int minK = 1e9;
        while (left <= right) {
            int mid = (1LL * left + right) / 2;
            if (isValid(mid, h, piles)) {
                minK = min(minK, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return minK;
    }
};