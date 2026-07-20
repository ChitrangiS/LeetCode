class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> temp;
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                temp.push_back(matrix[i][j]);
            }
        }
        sort(temp.begin(), temp.end());
        return temp[k - 1];
    }
};