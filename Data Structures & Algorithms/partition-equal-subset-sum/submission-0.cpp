class Solution {
public:
    bool canPartition(vector<int>& nums) {
        unordered_set<int> st;
        int req_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            req_sum += nums[i];
        }
        if (req_sum%2) {
            return false;
        } else {
            req_sum /= 2;
        }

        for (int i = 0; i < nums.size(); i++) {
            std::vector<int> to_add;
            for (auto u : st) {
                if (u + nums[i] == req_sum) {
                    return true;
                } else if (u + nums[i] < req_sum) {
                    to_add.push_back(u + nums[i]);
                }
            }
            st.insert(to_add.begin(), to_add.end());
            if (nums[i] == req_sum) {
                return true;
            } else if (nums[i] < req_sum) {
                st.insert(nums[i]);
            }
        }
        return st.find(req_sum) != st.end();
    }
};