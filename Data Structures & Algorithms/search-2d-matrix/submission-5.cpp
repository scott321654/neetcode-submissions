class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_num = matrix.size();
        int col_num = matrix[0].size();

        int top = 0, bottom = row_num - 1;

        while (top <= bottom) {
            int mid_row = top + (bottom - top) / 2;

            if (matrix[mid_row][0] > target) {
                bottom = mid_row - 1;

            } else if(matrix[mid_row][col_num - 1] < target) {
                top = mid_row + 1;
            } else {
                break;
            }
        }
        if (top > bottom) return false;
        int row = top + (bottom - top) / 2;
        int left = 0, right = col_num - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return false;
    }
};
