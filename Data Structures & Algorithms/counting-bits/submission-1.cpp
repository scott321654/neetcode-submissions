class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= n; ++i) {
            // 如果i是偶數，則i和i/2有相同的位1數
            // 如果i是奇數，則i的位1數等於i-1的位1數加1
            dp[i] = dp[i >> 1] + (i & 1);
        }
        
        return dp;
    }
};
