class Solution {
public:
    int solve(int i, int m, int n, vector<string>& strs,
              vector<vector<vector<int>>>& dp) {

        if (i < 0) {
            return 0;
        }

        if (dp[i][m][n] != -1) {
            return dp[i][m][n];
        }

        // Count 0 & 1
        int zero = 0;
        int one = 0;

        for (char x : strs[i]) {
            if (x == '0') {
                zero++;
            } else {
                one++;
            }
        }

        // not take
        int nottake = solve(i - 1, m, n, strs, dp);

        // take
        int take = 0;

        if (zero <= m && one <= n) {
            take = 1 + solve(
                i - 1,
                m - zero,
                n - one,
                strs,
                dp
            );
        }

        return dp[i][m][n] = max(take, nottake);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {

        int l = strs.size();

        vector<vector<vector<int>>> dp(
            l,
            vector<vector<int>>(
                m + 1,
                vector<int>(n + 1, -1)
            )
        );

        return solve(l - 1, m, n, strs, dp);
    }
};