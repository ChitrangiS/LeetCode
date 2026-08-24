class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        int sum = 0;

        for (int x : nums) {
            sum += x;
        }
        if (abs(target) > sum) {
            return 0;
        }
        if ((sum + target) % 2 != 0) {
            return 0;
        }
        int s1 = (sum + target) / 2;
        if (s1 < 0) {
            return 0;
        }
        vector<vector<int>> dp(n + 1, vector<int>(s1 + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int t = 0; t <= s1; t++) {
                // nottake
                dp[i][t] = dp[i - 1][t];
                // take
                if (nums[i - 1] <= t) {
                    dp[i][t] += dp[i - 1][t - nums[i - 1]];
                }
            }
        }
        return dp[n][s1];
    }
};