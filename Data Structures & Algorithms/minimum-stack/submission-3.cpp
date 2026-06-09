class MinStack {
private:
        stack<int> stk;
        stack<int> minstk;
public:
    MinStack() {

    }
    
    void push(int val) {
        stk.push(val);
        val = min(val, minstk.empty() ? val : minstk.top());
        minstk.push(val);
    }
    
    void pop() {
        stk.pop();
        minstk.pop();
    }
    
    int top() {
       return stk.top(); 
    }
    
    int getMin() {
        return minstk.top(); 
    }
};
