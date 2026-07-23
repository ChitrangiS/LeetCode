class Solution {
public:

    void solve(vector<int>& nums, vector<int>& ans, int i) {

        if (i == nums.size())
            return;

        ans[i] = nums[nums[i]];

        solve(nums, ans, i + 1);
    }

    vector<int> buildArray(vector<int>& nums) {

        vector<int> ans(nums.size());

        solve(nums, ans, 0);

        return ans;
    }
};