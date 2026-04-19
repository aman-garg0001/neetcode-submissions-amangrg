class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN, maxm = 1, minm = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                swap(maxm, minm);
            }
            maxm = max(nums[i], maxm*nums[i]);
            minm = min(nums[i], minm*nums[i]);
            ans = max(ans, maxm);
        }
        return ans;
    }
};