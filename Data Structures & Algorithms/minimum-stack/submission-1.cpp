class MinStack {
private:
    stack<int> stk;
    stack<int> minStk;
public:
    MinStack() {
        
    }
    
    void push(int val) 
    {
        stk.push(val);
        if (minStk.empty() || minStk.top() >= val)
        {
            minStk.push(val);
        }
        else
        {
            minStk.push(minStk.top());
        }
    }
    
    void pop() {
        minStk.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};
