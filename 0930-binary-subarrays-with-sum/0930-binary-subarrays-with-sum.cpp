class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0;
        int cnt = 0;
        for (int x : nums) {
            sum += x;

            int rem = sum - goal;
            if (mp.find(rem) != mp.end()) {
                cnt += mp[rem];
            }
            mp[sum]++;
        }
        return cnt;
    }
};