class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = 1;
        }
        for (auto u: mp) {
            int key = u.first, val = u.second;
            int tempAns = 1;
            key++;
            while (mp.find(key) != mp.end()) {
                tempAns += mp[key];
                mp.erase(key);
                key++;
            }
            mp[u.first] = tempAns;
            ans = max(ans, tempAns);
        }
        return ans;
    }
};