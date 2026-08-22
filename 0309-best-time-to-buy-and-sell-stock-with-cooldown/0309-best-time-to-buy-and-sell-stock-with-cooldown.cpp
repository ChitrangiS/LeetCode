class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        for (int day = n - 1; day >= 0; day--) {
            int buy = max(-prices[day] + dp[day + 1][0], dp[day + 1][1]);
            int sell = max(prices[day] + dp[day + 2][1], dp[day + 1][0]);

            dp[day][1] = buy;
            dp[day][0] = sell;
        }
        return dp[0][1];
    }
};