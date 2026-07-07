class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int slow = 0;
        int fast = slow + 1;
        int tmp = 0;

        while (fast < prices.size()) {
            if (prices[slow] > prices[fast]) {
                slow = fast;
            }
            tmp = max(tmp, (prices[fast] - prices[slow]));
            fast++;
        }

        return tmp;
    }
};
