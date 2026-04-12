class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> vp;
        for (int i = 0; i < position.size(); i++) {
            vp.push_back({position[i], speed[i]});
        }
        sort(vp.begin(), vp.end());
        stack<double> st;
        for (int i = 0; i < vp.size(); i++) {
            double time = ((double)(target - vp[i].first))/((double)vp[i].second);
            while (!st.empty() && st.top() <= time) {
                st.pop();
            }
            st.push(time);
        }
        return st.size();
    }
};