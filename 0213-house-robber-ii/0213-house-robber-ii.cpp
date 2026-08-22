class Solution {
public:
    // end is the last idx we consider
    int solve(int i, vector<int>& nums, int end, vector<int>& dp) {
        if (i > end) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int take = nums[i] + solve(i + 2, nums, end, dp);
        int nottake = solve(i + 1, nums, end, dp);

        return dp[i] = max(take, nottake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        if (n == 1) {
            return nums[0];
        }
        // first to second last
        int case1 = solve(0, nums, n - 2, dp1);
        // second to last
        int case2 = solve(1, nums, n - 1, dp2);

        return max(case1, case2);
    }
};