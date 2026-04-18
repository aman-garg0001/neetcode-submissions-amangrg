class Solution {
public:
    int numDecodings(string s) {
        int length = s.length();
        long long dp[length + 1];
        dp[0] = 1;
        for (int i = 0; i < length; i++) {
            if (s[i] == '0' and i == 0) {
                return 0;
            }

            if (s[i] != '0') {
                dp[i+1] = dp[i];
            } else {
                dp[i+1] = 0;
            }

            if (i == 0) {
                continue;
            }

            int lastTwoDigits = stoi(s.substr(i-1, 2));
            if (lastTwoDigits == 0) {
                return 0;
            } else if (s[i-1] != '0' and lastTwoDigits <= 26) {
                dp[i+1] += dp[i-1];
            }
        }
        return dp[length];
    }
};