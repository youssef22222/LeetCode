class StockSpanner {
    stack<pair<int, int>> st; //{my value , number of elements less than me}

public:
    StockSpanner() {}

    int next(int price) {
        int counter = 1;
        while (!st.empty()) {
            if (price >= st.top().first) {
                counter += st.top().second;
                st.pop();
            } else {
                break;
            }
        }
        st.push({price, counter});
        return counter;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */