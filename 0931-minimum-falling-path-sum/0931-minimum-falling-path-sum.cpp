class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();

        vector<vector<int>> dp = matrix;

        for (int i = n - 2; i >= 0; i--) {

            for (int j = 0; j < n; j++) {

                int down = dp[i + 1][j];

                int left = INT_MAX;

                if (j > 0) {
                    left = dp[i + 1][j - 1];
                }

                int right = INT_MAX;

                if (j < n - 1) {
                    right = dp[i + 1][j + 1];
                }

                dp[i][j] =
                    matrix[i][j] +
                    min({down, left, right});
            }
        }

        int ans = INT_MAX;

        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[0][j]);
        }

        return ans;
    }
};