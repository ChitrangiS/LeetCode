class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l = 0;
        long long r = num;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            long long square = mid * mid;

            if (square == num) {
                return true;
            }
            if (square < num) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};