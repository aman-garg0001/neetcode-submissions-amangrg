class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixProduct(n), suffixProduct(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                prefixProduct[i] = nums[i];
            } else {
                prefixProduct[i] = nums[i] * prefixProduct[i-1];
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                suffixProduct[i] = nums[i];
            } else {
                suffixProduct[i] = nums[i] * suffixProduct[i+1];
            }
        }

        vector<int> ans;
        
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                ans.push_back(suffixProduct[i+1]);
            } else if (i == n-1) {
                ans.push_back(prefixProduct[i-1]);
            } else {
                ans.push_back(prefixProduct[i-1] * suffixProduct[i+1]);
            }
        }

        return ans;
    }
};