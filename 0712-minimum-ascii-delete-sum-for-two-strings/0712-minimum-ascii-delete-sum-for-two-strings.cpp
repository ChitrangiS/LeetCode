class Solution {
public:
    int solve(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        if (i < 0) {
            int sum = 0;
            for (int k = 0; k <= j; k++) {
                sum += s2[k];
            }
            return sum;
        }
        if (j < 0) {
            int sum = 0;
            for (int k = 0; k <= i; k++) {
                sum += s1[k];
            }
            return sum;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        // curr same
        if (s1[i] == s2[j]) {
            return solve(i - 1, j - 1, s1, s2, dp);
        }
        // delet s1
        int delets1 = s1[i] + solve(i - 1, j, s1, s2, dp);
        // delet s2
        int delets2 = s2[j] + solve(i, j - 1, s1, s2, dp);

        return dp[i][j] = min(delets1, delets2);
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, s1, s2, dp);
    }
};