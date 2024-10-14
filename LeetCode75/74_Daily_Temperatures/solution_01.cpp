class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        stack<int> st;
        vector<int> nextGreaterElement(len);
        for (int i = 0; i < len; i++) {
            while (!st.empty()) {
                if (temperatures[st.top()] >= temperatures[i]) {
                    break;
                }
                nextGreaterElement[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return nextGreaterElement;
    }
};