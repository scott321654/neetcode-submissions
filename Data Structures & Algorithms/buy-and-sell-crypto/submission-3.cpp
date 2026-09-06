class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0, right = 0;
        int max_profit = 0;
        while(right < prices.size()) {
            if (prices[right] < prices[left]) {
                left = right;
            } else {
                max_profit = max(max_profit, prices[right] - prices[left]);
            }
            right++;
        }

        return max_profit;
    }
};