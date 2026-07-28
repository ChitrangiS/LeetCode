class Solution {
public:
    set<vector<int>>s;
    void getComination(vector<int>& candidates, int i, int target,
                       vector<vector<int>>& ans, vector<int>& combin) {

        if (i == candidates.size() || target < 0)
            return;
        if (target == 0) {
            if(s.find(combin)==s.end()){
                ans.push_back(combin);
                s.insert(combin);
            }
            return;
        }
        // single
        combin.push_back(candidates[i]);
        getComination(candidates, i + 1, target - candidates[i], ans, combin);

        // multiple
        getComination(candidates, i, target - candidates[i], ans, combin);

        // not take
        combin.pop_back();
        getComination(candidates, i + 1, target, ans, combin);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combin;
        getComination(candidates, 0, target, ans, combin);

        return ans;
    }
};