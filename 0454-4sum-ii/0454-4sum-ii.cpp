class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                     vector<int>& nums4) {
        int n = nums1.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int sum = nums1[i] + nums2[j];
                mp[sum]++;
            }
        }
        int cnt = 0;
        for (int k = 0; k < n; k++) {
            for (int l = 0; l < n; l++) {
                int sum = nums3[k] + nums4[l];

                if (mp.find(-sum) != mp.end()) {
                    cnt += mp[-sum];
                }
            }
        }
        return cnt;
    }
};