class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(nums1.begin(), nums1.end());
        unordered_set<int> st2(nums2.begin(), nums2.end());

        vector<int> a, b;

        for (int x : st1) {
            if (st2.count(x) == 0) {
                a.push_back(x);
            }
        }
        for (int x : st2) {
            if (st1.count(x) == 0) {
                b.push_back(x);
            }
        }
        return {a, b};
    }
};