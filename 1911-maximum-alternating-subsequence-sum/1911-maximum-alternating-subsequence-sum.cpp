class Solution {
public:
    long long solve(int i, int state, vector<int>& nums,
                    vector<vector<long long>>& dp) {
        if (i == nums.size()) {
            return 0;
        }
        if (dp[i][state] != -1) {
            return dp[i][state];
        }
        long long skip = solve(i + 1, state, nums, dp);
        long long take;
        if (state == 0) {
            take = +nums[i] + solve(i + 1, 1, nums, dp);
        } else {
            take = -nums[i] + solve(i + 1, 0, nums, dp);
        }
        return dp[i][state] = max(take, skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return solve(0, 0, nums, dp);
    }
};