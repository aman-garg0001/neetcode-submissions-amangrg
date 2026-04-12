class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int min = 1, max = piles.back();
        int ans = max;
        while (min <= max) {
            int mid = min + (max - min)/2;
            long hours = 0;
            for (int i = 0; i < piles.size(); i++) {
                hours += (piles[i]+mid-1)/mid;
            }
            if (hours > h) {
                min = mid+1;
            } else {
                ans = mid;
                max = mid - 1;
            }
        }
        return ans;
    }
};