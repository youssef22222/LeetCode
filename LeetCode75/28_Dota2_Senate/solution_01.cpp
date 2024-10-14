class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> D;
        queue<int> R;
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'D') {
                D.push(i);
            } else {
                R.push(i);
            }
        }
        while (R.size() && D.size()) {
            if (D.front() < R.front()) {
                D.push(D.front() + n);
                D.pop();
                R.pop();
            } else {
                R.push(R.front() + n);
                R.pop();
                D.pop();
            }
        }
        return (D.size() ? "Dire" : "Radiant");
    }
};