class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROW = matrix.size();
        int COL = matrix[0].size();

        int left = 0, right = COL * ROW - 1 ;

        while (left <= right) {
            int mid = left + (right - left)/2;
            int row = mid / COL;
            int col = mid % COL;

            if (target == matrix[row][col]) {
                return true;
            } else if (target > matrix[row][col]) {
                left = mid +1 ;
            } else {
                right = mid - 1;
            }

        }

        return false;

    }
};
