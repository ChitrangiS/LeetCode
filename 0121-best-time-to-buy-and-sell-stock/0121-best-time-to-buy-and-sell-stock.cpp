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

            int notBuy = solve(i + 1, 1, prices,dp);

            int buyStock = -prices[i] + solve(i + 1, 0, prices,dp);

            return dp[i][buy] = max(notBuy, buyStock);
        }

        else {

            int notSell = solve(i + 1, 0, prices,dp);

            int sellStock = prices[i];

            return dp[i][buy] = max(notSell, sellStock);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(0, 1, prices, dp);
    }
};