class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        set<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) == mp.end()) {
                vector<int> vec;
                mp[nums[i]] = vec;
            }
            mp[nums[i]].push_back(i);
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int requiredNumber = -nums[i] - nums[j];
                if (mp.find(requiredNumber) != mp.end()) {
                    for (auto u: mp[requiredNumber]) {
                        if (u != i and u != j) {
                            vector<int> temp = {nums[i], nums[j], nums[u]};
                            sort(temp.begin(), temp.end());
                            ans.insert(temp);
                            break;
                        }
                    }
                }
            }
        }

        vector<vector<int>> ans_vec;

        for (auto u : ans) {
            ans_vec.push_back(u);
        }

        return ans_vec;
    }
};