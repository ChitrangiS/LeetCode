class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }
        // find maxfreq
        int maxfreq = 0;
        for (auto it : freq) {
            maxfreq = max(maxfreq, it.second);
        }
        // count maxfreq
        int ans = 0;
        for (auto it : freq) {
            if (it.second == maxfreq) {
                ans += it.second;
            }
        }
        return ans;
    }
};