class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int open = 0, close = 0;
        vector<string> ans;
        n *= 2;
        genP(open, close, n, ans, "");
        return ans;
    }
private:
    void genP(int open, int close, int n, vector<string> &ans, string curr) {
        if (open + close == n && open == close) {
            ans.push_back(curr);
            return;
        }

        if (close < open) {
            genP(open, close + 1, n, ans, curr + ")");
        }
        
        if (open < n/2) {
            genP(open + 1, close, n, ans, curr + "(");
        }
    }
};