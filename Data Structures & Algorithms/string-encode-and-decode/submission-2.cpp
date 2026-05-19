class Solution {
public:

    string encode(vector<string>& strs) {
        string str;
        
        for (int i = 0; i < strs.size(); i++) {
            str += to_string(strs[i].size()) + '#' + strs[i];
        }
        
        return str;
    }

vector<string> decode(string s) {
    vector<string> dec_strs;
    int i = 0;
    
    while (i < s.size()) {
        // 從位置 i 開始往後找，一秒揪出 '#' 躲在第幾格
        int j = s.find('#', i); 
        
        // 算出長度（依舊是 # 的位置減去數字起點）
        int length = stoi(s.substr(i, j - i));
        
        // 精準切出文字：從 # 的下一格 (j + 1) 開始，抓 length 個字元
        dec_strs.push_back(s.substr(j + 1, length));
        
        // 跳躍！直接把指標推到下一個字串的起點
        i = j + 1 + length;
    }
    
    return dec_strs;
}
};
