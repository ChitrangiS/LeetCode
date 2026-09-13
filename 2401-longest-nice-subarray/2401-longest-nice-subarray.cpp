class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int ans = 0;
        int bits = 0;

        for (int r = 0; r < n; r++) {
            while ((bits & nums[r]) != 0) {
                bits ^= nums[l];
                l++;
            }

            bits |= nums[r];

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};