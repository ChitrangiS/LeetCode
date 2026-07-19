class Solution {
public:
    bool isPowerOfTwo(int n) {

        if (n <= 0)
            return false;

        long long power = 1;

        while (power < n) {
            power *= 2;
        }

        return power == n;
    }
};