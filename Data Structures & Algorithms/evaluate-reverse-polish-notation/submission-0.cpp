class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (auto& num : tokens)
        {
            if (num != "+" && num != "-" &&  num != "*" &&  num != "/")
            {
                stk.push(stoi(num));
            }
            else
            {
                int value2 = stk.top();
                stk.pop();
                int value1 = stk.top();
                stk.pop();

                if (num == "+")
                {
                    stk.push(value1 + value2);
                }
                else if (num == "-")
                {
                    stk.push(value1 - value2);
                }
                else if (num == "*")
                {
                    stk.push(value1 * value2);
                }
                else if (num == "/")
                {
                    stk.push(value1 / value2);
                }
            }
        }

        return stk.top();
    }
};
