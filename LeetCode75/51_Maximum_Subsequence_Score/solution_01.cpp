class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int len = nums1.size();
        vector<pair<int, int>> arr(len);
        for (int i = 0; i < len; i++) {
            arr[i] = {nums2[i], nums1[i]};
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(arr.rbegin(), arr.rend());
        long long mxVal = 0;
        long long sum = 0;
        for (int i = 0; i < len; i++) {
            sum += arr[i].second;
            if (pq.size() == k) {
                sum -= pq.top();
                pq.pop();
            }
            pq.push(arr[i].second);
            if (pq.size() == k) {
                mxVal = max(mxVal, sum * arr[i].first);
            }
        }
        return mxVal;
    }
};
