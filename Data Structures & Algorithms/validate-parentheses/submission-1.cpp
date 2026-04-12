class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char, char> paranthesisPair = {{')', '('}, {']', '['}, {'}', '{'}};

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' or s[i] == '{' or s[i] == '[') {
                st.push(s[i]);
            } else if (!st.empty() and paranthesisPair[s[i]] == st.top()) {
                st.pop();
            }  else {
                return false;
            }
        }

        return st.empty();
    }
};
