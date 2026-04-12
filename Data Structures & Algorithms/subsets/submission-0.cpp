class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(nums, 0, temp, ans);
        return ans;
    }

    void backtrack(vector<int>& nums, int i, vector<int> temp, vector<vector<int>> &ans) {
        if (i == nums.size()) {
            ans.push_back(temp);
            return;
        }
        backtrack(nums, i+1, temp, ans);
        temp.push_back(nums[i]);
        backtrack(nums, i+1, temp, ans);
    }
};