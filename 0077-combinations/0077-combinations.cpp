class Solution {
public:
    void possible(int n, int k, int i, vector<vector<int>>& ans,
                  vector<int>& combin) {

        if (combin.size() == k) {
            ans.push_back(combin);
            return;
        }
        if (i > n)
            return;

        combin.push_back(i);
        possible(n, k, i + 1, ans, combin);
        combin.pop_back();
        possible(n, k, i + 1, ans, combin);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> combin;

        possible(n, k, 1, ans, combin);
        return ans;
    }
};