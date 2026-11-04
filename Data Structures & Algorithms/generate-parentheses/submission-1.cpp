class Solution {
    vector<string> res;

    void backtrace(string curr, int n, int open, int close) {
        if (open == n && close == n) {
            res.push_back(curr);
            return;
        }

        if (open < n) {
            curr.push_back('(');
            backtrace(curr, n, open + 1, close);
            curr.pop_back();
        }

        if (close < open) {
            curr.push_back(')');
            backtrace(curr, n, open, close + 1);
            curr.pop_back();
        }

        
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        string curr = "";
        backtrace(curr, n, 0, 0);
        
        return res;
    }
};
