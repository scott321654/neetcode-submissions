class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
		stack<int> stk;
		vector<int> result(temperatures.size(), 0);	

		for (int i = 0; i < temperatures.size(); i++) {
			while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
				int prev = stk.top();
				stk.pop();
				result[prev] = i - prev;
				cout << "prev: " << prev << " i: " << i << " result: " << result[prev] << endl;
			}
			stk.push(i);	
		}

		return result;
    }
};