class Solution {
public:
    int isPossible(vector<int>& nums, int divisor, int threshold) {
        int sum = 0;
        for (int x : nums) {
            sum += (x + divisor - 1) / divisor;
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int h = *max_element(nums.begin(), nums.end());

        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (isPossible(nums, mid, threshold)) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};