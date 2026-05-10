class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        int n = temperatures.size();
        vector<int> ans(n);
        ans[n-1] = 0;
        st.push({temperatures.back(), n - 1});

        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && temperatures[i] >= st.top().first) {
                st.pop();
            }
            if (st.empty()) {
                st.push({temperatures[i], i});
                ans[i] = 0;
            } else {
                ans[i] = st.top().second - i;
                st.push({temperatures[i], i});
            }
        }

        return ans;
    }
};