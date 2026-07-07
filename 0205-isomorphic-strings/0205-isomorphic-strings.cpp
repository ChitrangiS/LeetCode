class Solution {
public:
    bool isIsomorphic(string s, string t) {

        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for (int i = 0; i < s.size(); i++) {
            char s1 = s[i]; // curr
            char t1 = t[i];

            if (!mp1.count(s1) && !mp2.count(t1)) {
                mp1[s1] = t1;
                mp2[t1] = s1;
            } else if (mp1[s1] != t1 || mp2[t1] != s1) {
                return false;
            }
        }
        return true;
    }
};