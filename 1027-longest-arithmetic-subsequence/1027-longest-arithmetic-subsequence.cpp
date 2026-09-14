class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();

        int ans = 2;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int diff = nums[j] - nums[i];
                int last = nums[j];
                int len = 2;

                for (int k = j + 1; k < n; k++) {
                    if (nums[k] - last == diff) {
                        len++;
                        last = nums[k];
                    }
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};