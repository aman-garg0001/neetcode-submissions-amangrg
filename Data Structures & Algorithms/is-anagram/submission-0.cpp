class Solution {
public:
    bool isAnagram(string s, string t) {
        int wordFreqS[26] = {0}, wordFreqT[26] = {0};
        if (s.length() != t.length()) {
            return false;
        }
        for (int i = 0; i < s.length(); i++) {
            wordFreqS[s[i] - 'a']++;
            wordFreqT[t[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (wordFreqS[i] != wordFreqT[i]) {
                return false;
            }
        }        
        return true;
    }
};
