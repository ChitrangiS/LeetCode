class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
            int n = nums.size();
    int i = 0;
    long long sum = 0, maxi = 0;
    unordered_map<int, int> freq;

    for(int j = 0; j < n; j++) {
        sum += nums[j];
        freq[nums[j]]++;

        if(j - i + 1 > k) {
            sum -= nums[i];
            freq[nums[i]]--;

            if(freq[nums[i]] == 0)
                freq.erase(nums[i]);

            i++;
        }

        if(j - i + 1 == k && freq.size() == k)
            maxi = max(maxi, sum);
    }

    return maxi;
    }
};