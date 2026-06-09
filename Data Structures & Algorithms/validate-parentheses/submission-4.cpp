class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int i = 0;
        while (i < s.size()) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
               stk.push(s[i]);
            } else {
                if (stk.empty()) return false; 
                if (s[i] == ')') {
                    if (stk.top() != '(')
                        return false;
                } else if (s[i] == ']') {
                    if (stk.top() != '[')
                        return false;
                } else if (s[i] == '}') {
                    if (stk.top() != '{')
                        return false;
                }
                stk.pop();
            }
            i++;
        }
        return stk.empty();
    }
};