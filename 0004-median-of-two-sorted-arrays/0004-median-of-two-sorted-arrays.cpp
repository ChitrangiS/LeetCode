class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(),
              back_inserter(ans));

        int n = ans.size();

        if (n % 2)
            return ans[n / 2];

        return (ans[n / 2] + ans[n / 2 - 1]) / 2.0;
    }
};