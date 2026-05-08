
class Solution
{
public:
    bool isValid(string s)
    {
        if (s.size() == 0)
            return true;
        else if (s.size() == 1)
            return false;

        std::stack<char> stk;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ')')
            {
                if (stk.empty() || stk.top() != '(')
                    return false;
                else
                    stk.pop();
            }
            else if (s[i] == ']')
            {
                if (stk.empty() || stk.top() != '[')
                    return false;
                else
                    stk.pop();
            }
            else if (s[i] == '}')
            {
                if (stk.empty() || stk.top() != '{')
                    return false;
                else
                    stk.pop();
            }
            else
            {
                stk.push(s[i]);
            }
        }

        return stk.empty();
    }
};
