class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ptr = 0;
        int ans = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (sum < 0 && ptr < i) {
                sum -= nums[ptr];
                ptr++;
            }
            sum += nums[i];
            ans = max(ans, sum);
            // cout << ptr << " " << sum << " " << ans << endl;
        }
        return ans;
    }
};