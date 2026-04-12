class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            int maxm = 0;
            for (int j = 0; j < i - 1; j++) {
                maxm = max(maxm, dp[j]);
            }
            dp[i] = nums[i] + maxm;
        }
        if (nums.size() > 1) {
            return max(dp[n-1], dp[n-2]);
        } else {
            return dp[0];
        }
    }
};