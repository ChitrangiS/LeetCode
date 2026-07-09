class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        string ans = "";
        unordered_set<string> valid;
        for (string word : words) {

            // word size 1 and uska prefix valid mai already avail
            if (word.size() == 1 ||
                valid.count(word.substr(0, word.size() - 1))) {
                valid.insert(word);

                if (word.size() > ans.size()) {
                    ans = word;
                }
            }
        }
        return ans;
    }
};