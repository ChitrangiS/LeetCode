class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        string ans="";
        unordered_map<char, int> mp;
        for (char ch : s) {
            mp[ch]++;
        }
        priority_queue<pair<int, char>> pq;

        for (auto it : mp) {
            pq.push({it.second, it.first});
        }
        while(!pq.empty())
        {
            auto[f,c]=pq.top();
            ans.append(f,c);
            pq.pop();
        }
        return ans;
    
    }
};