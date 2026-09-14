class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());

        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long operation = 0;
            for (int balls : nums) {
                operation += (balls - 1) / mid;
            }
            if (operation <= maxOperations) {
                r=mid-1;
            } else {
                l=mid+1;
            }
        }
        return l;
    }
};