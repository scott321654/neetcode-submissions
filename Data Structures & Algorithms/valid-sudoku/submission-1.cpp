class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> row(9), col(9), grid(9);

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size();j++)
            {
                char num = board[i][j];
                if (num == '.') continue;
                if (row[i].count(num) || col[j].count(num) || grid[i/3*3+j/3].count(num))
                {
                    return false;
                }
                row[i].insert(num);
                col[j].insert(num);
                grid[i/3*3+j/3].insert(num);
            }
        }

        return true;
    }
};
