class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> st;
        for (char c : allowed) {
            st.insert(c);
        }
        int ans = 0;
        for (string word : words) {
            bool valid = true;

            for (char ch : word) {
                if (st.find(ch) == st.end()) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                ans++;
            }
        }
        return ans;
    }
};