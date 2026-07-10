class Solution {
public:
    int isPossible(vector<int>& weights, int capacity) {
        int days = 1;
        int load = 0;

        for (int x : weights) {
            if (load + x <= capacity) {
                load += x;
            } else {
                days++;
                load = x;
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());

        int high = 0;
        for (int x : weights)
            high += x;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(weights, mid) <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};