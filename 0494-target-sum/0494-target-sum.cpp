class Solution {
public:
    int solve(int i, int s1, vector<int>& nums,vector<vector<int>>& dp) {
        if (i == 0) {
            if (s1 == 0 && nums[0] == 0) {
                return 2;
            }
            if (s1 == 0 || s1 == nums[0]) {
                return 1;
            }
            return 0;
        }
        if (dp[i][s1] != -1) {
			return dp[i][s1];
		}
        // dont take
        int nottake = solve(i - 1, s1, nums, dp);
        int take = 0;
        if (nums[i] <= s1) {
            take = solve(i - 1, s1 - nums[i], nums, dp);
        }
        return dp[i][s1]=take + nottake;
    }
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
        if(s1<0){
            return 0;
        }
        vector<vector<int>>dp(n,vector<int>(s1+1,-1));
        return solve(n - 1, s1, nums, dp);
    }
};