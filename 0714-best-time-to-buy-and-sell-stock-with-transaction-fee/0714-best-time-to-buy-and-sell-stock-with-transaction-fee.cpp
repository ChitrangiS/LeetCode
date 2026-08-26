class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {

            
            int notBuy = dp[i + 1][1];

            int buyStock =
                -prices[i] + dp[i + 1][0];

            dp[i][1] = max(notBuy, buyStock);

            int notSell = dp[i + 1][0];

            int sellStock =
                prices[i] - fee + dp[i + 1][1];

            dp[i][0] = max(notSell, sellStock);
        }

        return dp[0][1];
    }
};