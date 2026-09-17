class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> mp;
        for (char c : words[0]) {
            mp[c]++;
        }

        for (int i = 1; i < words.size(); i++) {
            unordered_map<char, int> curr;

            for (char c : words[i]) {
                curr[c]++;
            }

            for (auto& it : mp) {
                it.second = min(it.second, curr[it.first]);
            }
        }
        vector<string> ans;

        for (auto it : mp) {
            while (it.second > 0) {
                ans.push_back(string(1, it.first));
                it.second--;
            }
        }

        return ans;
    }
};