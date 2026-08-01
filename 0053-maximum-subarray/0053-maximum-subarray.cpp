class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int currsum = 0;
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            currsum += nums[i];
            maxi = max(currsum, maxi);

            if (currsum < 0) {
                currsum = 0;
            }
        }
        return maxi;
    }
};