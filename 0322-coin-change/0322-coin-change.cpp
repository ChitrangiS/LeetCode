class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX));

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {

            for (int a = 0; a <= amount; a++) {

                dp[i][a] = dp[i - 1][a];

                if (coins[i - 1] <= a && dp[i][a - coins[i - 1]] != INT_MAX) {

                    dp[i][a] = min(dp[i][a], 1 + dp[i][a - coins[i - 1]]);
                }
            }
        }

        if (dp[n][amount] == INT_MAX) {
            return -1;
        }

        return dp[n][amount];
    }
};
