class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--) {
            // buy=1
            int notbuy = dp[i + 1][1];
            int buystock = -prices[i] + dp[i + 1][0];
            dp[i][1] = max(notbuy, buystock);
            // sell
            int notsell = dp[i + 1][0];
            int sellstock = prices[i] + dp[i + 1][1];
            dp[i][0] = max(notsell, sellstock);
        }
        return dp[0][1];
    }
};