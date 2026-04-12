class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> minArr(n), maxArr(n);
        int minm = INT_MAX;
        int maxm = INT_MIN;
        for (int i = 0; i < n; i++) {
            minm = min(prices[i], minm);
            minArr[i] = minm;
        }
        for (int i = n - 1; i >= 0; i--) {
            maxm = max(prices[i], maxm);
            maxArr[i] = maxm;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, maxArr[i] - minArr[i]);
        }
        return ans;
    }
};
