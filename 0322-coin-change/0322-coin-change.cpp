class Solution {
public:
    int solve(int i, int amount, vector<int>& coins,vector<vector<int>>& dp) {
        if (amount == 0) {
            return 0;
        }
        if (i < 0) {
            return INT_MAX;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        // dont take
        int nottake = solve(i - 1, amount, coins,dp);
        // take
        int take = INT_MAX;
        if (coins[i] <= amount) {
            int result = solve(i, amount - coins[i], coins,dp);

            if (result != INT_MAX) {
                take = 1 + result;
            }
        }
        return dp[i][amount]=min(take, nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = solve(n - 1, amount, coins,dp);

        if (ans == INT_MAX) {
            return -1;
        }
        
        return ans;
    }
};