class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int current = 1;
        int index = 0;

        while (true) {

            if (index < arr.size() && arr[index] == current) {
                index++;
            }
            else {
                k--;

                if (k == 0)
                    return current;
            }

            current++;
        }
    }
};