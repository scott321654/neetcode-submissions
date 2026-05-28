class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 用一個 9x9 的布林陣列來取代 9 個 set
        // row[i][num] 代表第 i 行中，數字 num 是否出現過
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool grid[9][9] = {false};
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                
                // 將字元 '1'~'9' 轉換成索引 0~8
                int num = board[i][j] - '1'; 
                int k = i / 3 * 3 + j / 3; // 九宮格編號
                
                // 檢查是否重複
                if (row[i][num] || col[j][num] || grid[k][num]) {
                    return false;
                }
                
                // 標記為已出現
                row[i][num] = true;
                col[j][num] = true;
                grid[k][num] = true;
            }
        }
        return true;
    }
};