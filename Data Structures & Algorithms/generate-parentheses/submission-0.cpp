class Solution {
    void backtrace(int open, int close, vector<string> &res, string curr, int n) {
        if (open == n && close == n) {
            res.push_back(curr);
            return;
        }
        if (open < n) {
            curr.push_back('(');
            backtrace(open + 1, close, res, curr, n);
            curr.pop_back();
        }

        if (close < open) {
            curr.push_back(')');
            backtrace(open, close + 1, res, curr, n);
            curr.pop_back();
        }

        return;
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrace(0, 0, res, "", n);
        return res;
    }
};
