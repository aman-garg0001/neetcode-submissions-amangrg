class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = m*n - 1;
        int mid;

        while (left <= right) {
            mid = (right - left)/2 + left;
            int num = matrix[mid/n][mid%n];
            cout << mid << " " << mid/n << " " << mid%n << " " << num << endl;
            if (target > num) {
                left = mid + 1;
            } else if (target < num) {
                right = mid - 1;
            } else {
                return true;
            }
        }

        return false;
    }
};
