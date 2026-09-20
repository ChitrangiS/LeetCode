class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int l = 0;
        int r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (letters[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if (l == n) {
            return letters[0];
        }

        return letters[l];
    }
};