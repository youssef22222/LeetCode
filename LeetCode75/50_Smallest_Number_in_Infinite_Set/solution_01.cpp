class SmallestInfiniteSet {
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> freq;

public:
    SmallestInfiniteSet() {
        int mxNum = 1001;
        freq = vector<int>(mxNum, 1);
        for (int i = 1; i < mxNum; i++) {
            pq.push(i);
        }
    }

    int popSmallest() {
        int smallest = pq.top();
        pq.pop();
        freq[smallest]--;
        return smallest;
    }

    void addBack(int num) {
        if (!freq[num]) {
            pq.push(num);
            freq[num]++;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */