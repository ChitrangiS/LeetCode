class Solution {
public:
    int solve(int day, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (day >= prices.size()) {
            return 0;
        }
        if (dp[day][buy] != -1) {
            return dp[day][buy];
        }
        while (buy == 1) {
            int take = -prices[day] + solve(day + 1, 0, prices, dp);
            int nottake = solve(day + 1, 1, prices, dp);

            return dp[day][buy] = max(take, nottake);
        }
        int sell = prices[day] + solve(day + 2, 1, prices, dp);
        int notsell = solve(day + 1, 0, prices, dp);

        return dp[day][buy] = max(sell, notsell);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};