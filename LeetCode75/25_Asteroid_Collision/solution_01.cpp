class Solution {
public:
    bool inSameDirection(int asteroid1, int asteroid2) {
        return ((asteroid1 < 0 && asteroid2 < 0) ||
                (asteroid1 > 0 && asteroid2 > 0));
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        //- <= left  + => right
        for (int i = 0; i < asteroids.size(); i++) {
            if (st.empty() || inSameDirection(st.top(), asteroids[i]) ||
                (st.top() < asteroids[i])) {
                st.push(asteroids[i]);
            } else {
                bool isExplode = false;
                while (
                    !(st.empty() || inSameDirection(st.top(), asteroids[i]))) {
                    if (abs(st.top()) == abs(asteroids[i])) {
                        st.pop();
                        isExplode = true;
                        break;
                    } else if (abs(st.top()) < abs(asteroids[i])) {
                        st.pop();
                    } else {
                        isExplode = true;
                        break;
                    }
                }
                if (!isExplode) {
                    st.push(asteroids[i]);
                }
            }
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};