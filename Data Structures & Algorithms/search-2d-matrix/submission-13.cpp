class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROW = matrix.size();
        int COL = matrix[0].size();

        int left = 0, right = COL * ROW;

        while (left < right) {
            int mid = left + (right - left)/2;
            int row = mid / COL;
            int col = mid % COL;

            if (target <= matrix[row][col]) {
                right = mid;
            } else if (target > matrix[row][col]) {
                left = mid + 1;
            } 
        }
        int target_row = right / COL;
        int target_col = right % COL;
        if (right < COL * ROW && matrix[target_row][target_col] == target)
            return true;
        return  false ;

    }
};
