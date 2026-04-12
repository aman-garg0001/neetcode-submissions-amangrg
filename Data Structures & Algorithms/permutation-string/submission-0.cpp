class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int ptr = 0;
        vector<int> freq(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            freq[s1[i] - 'a']++;
        }

        vector<int> slidingFreq(26, 0); 

        for (int i = 0; i < s2.length(); i++) {
            slidingFreq[s2[i] - 'a']++;

            if (slidingFreq == freq) {
                return true;
            }

            while (slidingFreq[s2[i] - 'a'] > freq[s2[i] - 'a']) {
                slidingFreq[s2[ptr] - 'a']--;
                ptr++;
            }
        }

        return false;
    }
};