class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for (auto u: strs) {
            int size = u.length();
            string prefix = '[' + to_string(size) + ']';
            ans += prefix + u;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while (i < s.length()) {
            if (s[i] == '[') {
                i++;
                string chunkLength = "";
                while(s[i] != ']') {
                    chunkLength += s[i];
                    i++;
                }
                i++;
                int num = stoi(chunkLength);
                ans.push_back(s.substr(i, num));
                i += num;
            }
        }
        return ans;
    }
};
