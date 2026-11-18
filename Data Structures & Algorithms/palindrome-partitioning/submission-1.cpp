class Solution {
    vector<vector<string>> res;
    vector<string> cur;

    bool palindrome(string s) {
        int l = 0, r = s.size() - 1;

        while (l <= r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
    
    void backtrace(string s, int i) {
        if (i >= s.size()) {
            res.push_back(cur);
            return;
        }

        for (int j = i; j < s.size(); j++) {
            string sub = s.substr(i, j - i + 1);
            if (palindrome(sub)) {
                cur.push_back(sub);
                backtrace(s, j  + 1);
                cur.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        
        backtrace(s, 0);
        return res;
    }
};
