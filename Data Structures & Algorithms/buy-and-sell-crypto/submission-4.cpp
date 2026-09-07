class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0, right = 0, max_profit = 0;

        while (right < prices.size()) {
            if (prices[left] > prices[right]) {
                left = right;
            } else {
                max_profit = max(prices[right] - prices[left], max_profit);
                right++;
            }
        }

        return max_profit;
    }
};
