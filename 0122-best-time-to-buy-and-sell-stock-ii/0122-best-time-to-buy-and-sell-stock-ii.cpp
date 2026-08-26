class Solution {
public:
    int solve(int i, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (i == prices.size()) {
            return 0;
        }
        if (dp[i][buy] != -1) {
            return dp[i][buy];
        }
        if (buy == 1) {
            // dont buy
            int notbuy = solve(i + 1, 1, prices, dp);
            int buystock = -prices[i] + solve(i + 1, 0, prices, dp);
            return dp[i][buy] = max(notbuy, buystock);
        }
        // sell
        int notsell = solve(i + 1, 0, prices, dp);
        int sellstock = prices[i] + solve(i + 1, 1, prices, dp);
        return dp[i][buy] = max(notsell, sellstock);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};