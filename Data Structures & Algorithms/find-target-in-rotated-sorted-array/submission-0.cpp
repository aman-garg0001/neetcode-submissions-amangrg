class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot = getPivot(nums);
        cout << pivot;
        int firstHalfIdx = lower_bound(nums.begin(), nums.begin() + pivot - 1, target) - nums.begin();
        int secondHalfIdx = lower_bound(nums.begin() + pivot, nums.end(), target) - nums.begin();

        if (firstHalfIdx < nums.size() and nums[firstHalfIdx] == target) {
            return firstHalfIdx;
        }

        if (secondHalfIdx < nums.size() and nums[secondHalfIdx] == target) {
            return secondHalfIdx;
        }

        return -1;
    }

    int getPivot(vector<int> &nums) {
        int len = nums.size();
        int i = 0;
        int j = len-1;
        int centre = i + (j-i)/2;
        while (i < j) {
            centre = i + (j-i)/2;
            cout << centre << " ";
            if (nums[centre] > nums[len-1]) {
                i = centre + 1;
            } else {
                j = centre;
            }
        }
        cout << centre;
        return i;
    }
};
