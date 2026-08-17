class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        vector<bool> used(26, false);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string ans;

        for (char ch : s) {

            freq[ch - 'a']--;

            if (used[ch - 'a'])
                continue;

            while (!ans.empty() && ans.back() > ch &&
                   freq[ans.back() - 'a'] > 0) {

                used[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(ch);
            used[ch - 'a'] = true;
        }

        return ans;
    }
};