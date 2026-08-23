class Solution {
public:
    bool solve(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0) {
            return true;
        }
        // mtlb target nhi hua and no ele
        if (i < 0) {
            return false;
        }
        if (dp[i][target] != -1) {
            return dp[i][target];
        }
        // take
        bool take = false;
        if (nums[i] <= target) {
            take = solve(i - 1, target - nums[i], nums, dp);
        }

        int nottake = solve(i - 1, target, nums, dp);
        return dp[i][target] = take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for (int x : nums) {
            sum += x;
        }
        if (sum % 2 != 0) {
            return false;
        }
        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(n - 1, target, nums, dp);
    }
};