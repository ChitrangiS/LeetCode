class Solution {
public:
    int solve(int i, int buy, int fee, vector<int>& prices,
              vector<vector<int>>& dp) {
        if (i == prices.size()) {
            return 0;
        }
        if (dp[i][buy] != -1) {
            return dp[i][buy];
        }
        if (buy == 1) {
            int notbuy = solve(i + 1, 1, fee, prices, dp);
            int buystock = -prices[i] + solve(i + 1, 0, fee, prices, dp);
            return dp[i][buy] = max(notbuy, buystock);
        } else {
            int notsell = solve(i + 1, 0, fee, prices, dp);
            int sellstock = prices[i] - fee + solve(i + 1, 1, fee, prices, dp);
            return dp[i][buy] = max(notsell, sellstock);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, fee, prices, dp);
    }
};