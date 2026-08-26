class Solution {
public:
    int solve(int i, int buy, int cap, vector<int>& prices,
              vector<vector<vector<int>>>& dp) {
        if (i == prices.size() || cap == 0) {
            return 0;
        }
        if (dp[i][buy][cap] != -1) {
            return dp[i][buy][cap];
        }
        if (buy == 1) {
            int notbuy = solve(i + 1, 1, cap, prices, dp);
            int buystock = -prices[i] + solve(i + 1, 0, cap, prices, dp);
            return dp[i][buy][cap] = max(notbuy, buystock);
        } else {
            int notsell = solve(i + 1, 0, cap, prices, dp);
            int sellstock = prices[i] + solve(i + 1, 1, cap - 1, prices, dp);
            return dp[i][buy][cap] = max(notsell, sellstock);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return solve(0, 1, k, prices, dp);
    }
};