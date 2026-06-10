class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> result(temperatures.size());
        
        for (int i = 0; i < temperatures.size();i++) {
            while(!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                int prev = stk.top();
                stk.pop();
                result[prev] = i - prev;
            }
            stk.push(i);
        }

        return result;
    }
};
         