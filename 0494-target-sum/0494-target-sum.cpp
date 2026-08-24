class Solution {
public:
    int solve(int i, int s1, vector<int>& nums) {
        if (i == 0) {
            if (s1 == 0 && nums[0] == 0) {
                return 2;
            }
            if (s1 == 0 || s1 == nums[0]) {
                return 1;
            }
            return 0;
        }
        // dont take
        int nottake = solve(i - 1, s1, nums);
        int take = 0;
        if (nums[i] <= s1) {
            take = solve(i - 1, s1 - nums[i], nums);
        }
        return take + nottake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (int x : nums) {
            sum += x;
        }
        if (target > sum) {
            return 0;
        }
        if ((sum + target) % 2 != 0) {
            return 0;
        }
        int s1 = (sum + target) / 2;

        return solve(n - 1, s1, nums);
    }
};