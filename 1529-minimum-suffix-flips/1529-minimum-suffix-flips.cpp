class Solution {
public:
    int minFlips(string target) {
        int ans = 0;
        char current = '0';

        for (char c : target) {
            if (c != current) {
                ans++;
                current = c;
            }
        }
        return ans;
    }
};