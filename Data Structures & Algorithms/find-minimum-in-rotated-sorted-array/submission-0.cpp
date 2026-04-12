class Solution {
public:
    int findMin(vector<int> &nums) {
        int pivot = getPivot(nums);
        return nums[pivot];
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
