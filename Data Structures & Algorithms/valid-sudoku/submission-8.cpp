class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9] = {0}, col[9] = {0}, grid[9] = {0};
         for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.')
                    continue;
                if (row[i] & (1 << (board[i][j] - '1')) ||
                    col[j] &(1 << (board[i][j] - '1')) ||
                    grid[i/3*3+j/3] & (1 << (board[i][j] - '1'))) {
                    
                    return false;
                }
                row[i] |= 1 << (board[i][j] - '1');
                col[j] |= 1 << (board[i][j] - '1');
                grid[i/3*3+j/3] |= 1 << (board[i][j] - '1');
            }
         }
        return true;
    }
};