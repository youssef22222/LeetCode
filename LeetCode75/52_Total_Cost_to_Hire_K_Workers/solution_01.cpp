class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> firstCandidates;
        priority_queue<int, vector<int>, greater<int>> lastCandidates;
        int len = costs.size();
        for (int i = 0, j = len - 1; i <= j && i < candidates; i++, j--) {
            if (i != j) {
                firstCandidates.push(costs[i]);
                lastCandidates.push(costs[j]);
            } else {
                firstCandidates.push(costs[i]);
            }
        }
        int left = candidates - 1;
        int right = len - candidates;
        long long totalCost = 0;
        while (k) {
            if (firstCandidates.size() && lastCandidates.size()) {
                if (firstCandidates.top() <= lastCandidates.top()) {
                    totalCost += firstCandidates.top();
                    firstCandidates.pop();
                    left++;
                    if (left < right) {
                        firstCandidates.push(costs[left]);
                    }
                } else {
                    totalCost += lastCandidates.top();
                    lastCandidates.pop();
                    right--;
                    if (left < right) {
                        lastCandidates.push(costs[right]);
                    }
                }
            } else if (firstCandidates.size()) {
                totalCost += firstCandidates.top();
                firstCandidates.pop();
                left++;
                if (left < right) {
                    firstCandidates.push(costs[left]);
                }
            } else if (lastCandidates.size()) {
                totalCost += lastCandidates.top();
                lastCandidates.pop();
                right--;
                if (left < right) {
                    lastCandidates.push(costs[right]);
                }
            } else {
                break;
            }
            k--;
        }
        return totalCost;
    }
};