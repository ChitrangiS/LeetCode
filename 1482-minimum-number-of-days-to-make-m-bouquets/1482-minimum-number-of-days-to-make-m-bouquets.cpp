class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int bouquet = 0;
            int flower = 0;

            for (int i = 0; i < n; i++) {
                if (bloomDay[i] <= mid) {
                    flower++;

                    if (flower == k) {
                        bouquet++;
                        flower = 0;
                    }
                } else {
                    flower = 0;
                }
            }
            if (bouquet >= m) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};