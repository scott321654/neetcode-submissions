class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> row(9), column(9), block(9);

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if  (board[i][j] == '.')
                    continue;
                if (row[i].count(board[i][j])
                 || column[j].count(board[i][j])
                 || block[i/3*3+ j / 3].count(board[i][j]))
                {
                    return false;
                }
               row[i].insert(board[i][j]);
               column[j].insert(board[i][j]);
               block[i/3*3+ j / 3].insert(board[i][j]);
            }
        } 

        return true;
    }
};
