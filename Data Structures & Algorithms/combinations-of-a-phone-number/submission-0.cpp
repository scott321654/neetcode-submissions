class Solution {
    vector<string> digstr = {"","", "abc","def","ghi","jkl","mno", "pqrs","tuv","wxyz"};
    vector<string> res;
    string cur;
public:
    void backtracking(string digits, int i) {
        if (i == digits.size()) {
            res.push_back(cur);
            return;
        }
        
        for (int j = 0; j < digstr[digits[i] - '0'].size(); j++) {
            cur.push_back(digstr[digits[i] - '0'][j]);
            backtracking(digits, i + 1);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits == "") return res;
        backtracking(digits, 0);
        
        return res;
    }
};