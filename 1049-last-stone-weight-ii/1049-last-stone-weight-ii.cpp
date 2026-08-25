class Solution {
public:
    int solve(int i, int target, vector<int>& stones, vector<vector<int>>& dp) {
        if (i < 0) {
            return 0;
        }
        if (dp[i][target] != -1) {
            return dp[i][target];
        }
        // nottake
        int nottake = solve(i - 1, target, stones, dp);
        // take
        int take = 0;
        if (stones[i] <= target) {
            take = stones[i] + solve(i - 1, target - stones[i], stones, dp);
        }
        return dp[i][target] = max(take, nottake);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;

        for (int x : stones) {
            sum += x;
        }
        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        int subsetsum = solve(n - 1, target, stones, dp);
        return sum - 2 * subsetsum;
    }
};