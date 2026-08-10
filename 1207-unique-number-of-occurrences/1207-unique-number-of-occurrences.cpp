class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (int x : arr) {
            mp[x]++;
        }
        vector<int> freq;
        for (auto it : mp) {
            freq.push_back(it.second);
        }
        for (int i = 0; i < freq.size(); i++) {
            for (int j = i + 1; j < freq.size(); j++) {

                if (freq[i] == freq[j]) {
                    return false;
                }
            }
        }
        return true;
    }
};