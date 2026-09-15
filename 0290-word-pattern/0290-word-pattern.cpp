class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        for (int i = 0; i < pattern.size(); i++) {

            if (!(ss >> word)) {
                return false;
            }
            char c = pattern[i];

            if (!mp1.count(c) && !mp2.count(word)) {
                mp1[c] = word;
                mp2[word] = c;
            } else if (mp1[c] != word || mp2[word] != c) {
                return false;
            }
        }
        if (ss >> word) {
            return false;
        }
        return true;
    }
};