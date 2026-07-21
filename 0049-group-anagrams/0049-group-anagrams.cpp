class Solution {
public:
    bool isAnagram(string a, string b) {
        if (a.size() != b.size())
            return false;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a == b;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<bool> vis(n, false);
        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (vis[i])
                continue;

            vector<string> group;
            group.push_back(strs[i]);
            vis[i] = true;

            for (int j = i + 1; j < n; j++) {

                if (!vis[j] && isAnagram(strs[i], strs[j])) {

                    group.push_back(strs[j]);
                    vis[j] = true;
                }
            }

            ans.push_back(group);
        }

        return ans;
    }
};
