class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<long long>> dp(n + 1, vector<long long>(amount + 1, 0));

        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int a = 0; a <= amount; a++) {

                // not take
                dp[i][a] = dp[i - 1][a];

                if (coins[i - 1] <= a) {
                    dp[i][a] += dp[i][a - coins[i - 1]];

                    if (dp[i][a] > INT_MAX) {
                        dp[i][a] = INT_MAX;
                    }
                }
            }
        }

        return (int)dp[n][amount];
    }
};