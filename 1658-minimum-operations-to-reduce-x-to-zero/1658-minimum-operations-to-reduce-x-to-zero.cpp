class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int sum = 0;
        for(int c : nums) {
            sum += c;
        }

        int target = sum - x;

        if(target < 0) {
            return -1;
        }

        int l = 0;
        int sum2 = 0;
        int ans = -1;

        for(int r = 0; r < n; r++) {
            sum2 += nums[r];

            while(sum2 > target) {
                sum2 -= nums[l];
                l++;
            }

            if(sum2 == target) {
                ans = max(ans, r - l + 1);
            }
        }

        if(ans == -1) {
            return -1;
        }

        return n - ans;
    }
};