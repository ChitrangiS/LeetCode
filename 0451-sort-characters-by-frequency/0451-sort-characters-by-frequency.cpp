class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        int n = s.size();
        // freq of each char
        for (char ch : s) {
            freq[ch]++;
        }

        string ans = "";
        // maxfreq
        while (!freq.empty()) {
            char maxChar;
            int maxFreq = 0;

            for (auto it : freq) {
                if (it.second > maxFreq) {
                    maxFreq = it.second;
                    maxChar = it.first;
                }
            }
            while (maxFreq--) {
                ans += maxChar;
            }
            freq.erase(maxChar);
        }
        return ans;
    }
};