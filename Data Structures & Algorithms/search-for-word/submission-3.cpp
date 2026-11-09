class Solution {
    bool backtrace(int col, int row, int i, vector<vector<char>>& board, string word) {
        if (word.size() == i) {
            return true;
        }
        if (col < 0 || row < 0 || col >= board[0].size() || row >= board.size() || board[row][col] != word[i]) {
            return false;
        }
        
        board[row][col] = '*';
        bool ret = backtrace(col, row + 1, i + 1, board, word) ||
                   backtrace(col, row - 1, i + 1, board, word) ||
                   backtrace(col + 1, row, i + 1, board, word) ||
                   backtrace(col - 1, row, i + 1, board, word);
        board[row][col] = word[i];

        return ret;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[row].size(); ++col) {
                if (backtrace(col, row, 0, board, word))
                    return true;
            }
        }
        return false;
    }
};
