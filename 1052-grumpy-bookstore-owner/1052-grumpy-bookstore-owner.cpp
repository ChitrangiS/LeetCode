class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();

        int base = 0;
        int sum = 0;
        int maxSum = 0;
        int l = 0;

        for(int i = 0; i < n; i++) {
            if(grumpy[i] == 0) {
                base += customers[i];
            }
        }

        for(int r = 0; r < n; r++) {
            if(grumpy[r] == 1) {
                sum += customers[r];
            }

            if(r - l + 1 == minutes) {
                maxSum = max(maxSum, sum);

                if(grumpy[l] == 1) {
                    sum -= customers[l];
                }

                l++;
            }
        }

        return base + maxSum;
    }
};