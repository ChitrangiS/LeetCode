class Solution {
public:
    string longestWord(vector<string>& words) {
        int n = words.size();
        unordered_set<string> st(words.begin(), words.end());
        string ans = "";
        for (int i = 0; i < n; i++) {
            string word = words[i];
            bool valid = true;
            for (int j = 1; j < word.size(); j++) {
                string prefix = word.substr(0, j);

                if (st.find(prefix) == st.end()) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                if (word.size() > ans.size() ||
                    (word.size() == ans.size() && word < ans)) {
                    ans = word;
                }
            }
        }
        return ans;
    }
};