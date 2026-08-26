class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for (int x : nums) {
            int l = 0;
            int r = tails.size() - 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (tails[mid] < x) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if (l == tails.size()) {
                tails.push_back(x);
            } else {
                tails[l] = x;
            }
        }
        return tails.size();
    }
};