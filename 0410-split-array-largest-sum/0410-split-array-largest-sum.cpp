class Solution {
public:
    int countSubarrays(vector<int>& nums, int maxSum) {
        int subarrays = 1;
        int sum = 0;

        for (int x : nums) {
            if (sum + x <= maxSum) {
                sum += x;
            } else {
                subarrays++;
                sum = x;
            }
        }

        return subarrays;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());

        int high = 0;
        for (int x : nums)
            high += x;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (countSubarrays(nums, mid) <= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};