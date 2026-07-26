class Solution {
public:
    void solve(int i, vector<int>& subset, vector<int>& nums,
               vector<vector<int>>& ans) {
        int n = nums.size();
        if (i == n) {
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        solve(i + 1, subset, nums, ans);
        // backtrack
        subset.pop_back();
        solve(i + 1, subset, nums, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;

        solve(0, subset, nums, ans);

        return ans;
    }
};