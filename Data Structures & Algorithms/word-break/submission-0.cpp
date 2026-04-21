class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < s.length(); i++) {
            if (dp[i] == 0) {
                continue;
            }
            for (int j = 0; j < wordDict.size(); j++) {
                if (i + wordDict[j].length() <= s.length()
                 && s.substr(i, wordDict[j].length()) == wordDict[j]) {
                    dp[i+wordDict[j].length()] = 1;
                 }
            }
        }
        return dp[s.length()];
    }
};