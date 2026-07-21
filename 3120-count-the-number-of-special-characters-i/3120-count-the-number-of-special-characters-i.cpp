class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> upp;
        unordered_set<char> low;

        for (char x : word) {
            if (x >= 'a' && x <= 'z')
                low.insert(x);
            else
                upp.insert(x);
        }

        int ans = 0;

        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (low.count(ch) && upp.count(ch - 'a' + 'A'))
                ans++;
        }

        return ans;
    }
};