class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> tmpStk;
        int i = 0, tmp, a, b;
        
        while (i < tokens.size()) {
            if ((tokens[i] != "+") &&
                (tokens[i] != "-") && 
                (tokens[i] != "*") && 
                (tokens[i] != "/")) {
                tmpStk.push(stoi(tokens[i]));
            } else {
                if (tokens[i] == "+") {
                    a = tmpStk.top();
                    tmpStk.pop();
                    b = tmpStk.top();
                    tmpStk.pop();
                    tmp = b + a;
                    tmpStk.push(tmp);
                } else if (tokens[i] == "-") {
                    a = tmpStk.top();
                    tmpStk.pop();
                    b = tmpStk.top();
                    tmpStk.pop();
                    tmp = b - a;
                    tmpStk.push(tmp);
                
                } else if (tokens[i] == "*") {
                    a = tmpStk.top();
                    tmpStk.pop();
                    b = tmpStk.top();
                    tmpStk.pop();
                    tmp = b * a;
                    tmpStk.push(tmp);
                
                } else if (tokens[i] == "/") {
                    a = tmpStk.top();
                    tmpStk.pop();
                    b = tmpStk.top();
                    tmpStk.pop();
                    tmp = b / a;
                    tmpStk.push(tmp);
                } 
            }
            i++;
        }       
        
        return tmpStk.top();
    }
};

