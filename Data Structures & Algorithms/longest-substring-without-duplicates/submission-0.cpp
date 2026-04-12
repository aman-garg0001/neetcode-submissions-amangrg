class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int start = 0;
        int ans = 0;
        int curr = 0;
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
            if (mp[s[i]] > 1) {
                ans = max(ans, curr);
                while (mp[s[i]] > 1) {
                    mp[s[start++]]--;
                }
            }
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};