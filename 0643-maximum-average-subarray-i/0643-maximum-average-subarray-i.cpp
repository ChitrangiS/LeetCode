class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int l = 0;
        double ans = -1e9;
        for (int r = 0; r < n; r++) {
            sum += nums[r];

            while (r - l + 1 == k) {
                double avg = (double)sum / k;
                ans = max(ans, avg);
                sum -= nums[l];
                l++;
            }
        }
        return ans;
    }
};