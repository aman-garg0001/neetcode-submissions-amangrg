class Solution {
public:
    int characterReplacement(string s, int k) {
        int ptr = 0, ans = 1, maxm = 0;
        map<char, int> mp;
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
            maxm = max(mp[s[i]], maxm);
            if (mp.size() > 1) {
                while (mp.size() > 1 && ((i - ptr + 1) - maxm) > k) {
                    mp[s[ptr]]--;
                    if (mp[s[ptr]] == 0) {
                        mp.erase(s[ptr]);
                    }
                    ptr++;
                    maxm = getMapMax(mp);
                }
            }
            ans = max(ans, i - ptr + 1);
        }

        return ans;
    }

    int getMapMax(map<char, int> mp) {
        int maxm = INT_MIN;
        for (auto keyVal : mp) {
            maxm = max(maxm, keyVal.second);
        }
        return maxm;
    }
};