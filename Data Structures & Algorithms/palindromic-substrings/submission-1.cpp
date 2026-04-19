class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            ans++;
        }
        for (int i = 0; i < n-1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                ans++;
            }
        }
        for (int diff = 2; diff < n; diff++) {
            for (int i = 0; i < n-diff; i++) {
                if (s[i] == s[i+diff] and dp[i+1][i+diff-1]) {
                    dp[i][i+diff] = true;
                    ans++;
                }
            }
        }
        return ans;
    }
};