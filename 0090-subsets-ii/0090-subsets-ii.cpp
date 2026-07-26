class Solution {
public:
    void solve(int i, vector<vector<int>>& ans, vector<int>& nums, vector<int>& subset) {
        int n = nums.size();

        if (i == n) {
            ans.push_back(subset);
            return;
        }

        
        subset.push_back(nums[i]);
        solve(i + 1, ans, nums, subset);

        // Backtrack
        subset.pop_back();

        // Skip
        int idx = i + 1;
        while (idx < n && nums[idx] == nums[idx - 1]) {
            idx++;
        }

        
        solve(idx, ans, nums, subset);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> subset;

        solve(0, ans, nums, subset);

        return ans;
    }
};