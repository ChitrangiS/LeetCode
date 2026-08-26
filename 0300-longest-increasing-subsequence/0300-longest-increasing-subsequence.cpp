class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp) {
        if (i == 0) {
            return 1;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int ans = 1;
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                ans = max(ans, solve(j, nums, dp) + 1);
            }
        }
        return dp[i] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int ans = 1;
        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(i, nums, dp));
        }
        return ans;
    }
};