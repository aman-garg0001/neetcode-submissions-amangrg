class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> vec;
        backtrack(ans, vec, 0, 0, nums, target);
        return ans;
    }

    void backtrack(vector<vector<int>> &ans, vector<int> vec, int sum, int idx, vector<int>& candidates, int target) {
        if (idx >= candidates.size() or sum > target) {
            return;
        }
        if (sum == target) {
            ans.push_back(vec);
            return;
        }
        backtrack(ans, vec, sum, idx+1, candidates, target);
        sum += candidates[idx];
        vec.push_back(candidates[idx]);
        backtrack(ans, vec, sum, idx, candidates, target);
    }
};
