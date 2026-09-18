class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int x : nums) {
            mp[x]++;
        }
        vector<pair<int, int>> arr;
        for (auto it : mp) {
            arr.push_back({it.second, it.first});
        }
        sort(arr.begin(), arr.end());
        vector<int> ans;
        for (int i = arr.size() - k; i < arr.size(); i++) {
            ans.push_back(arr[i].second);
        }
        return ans;
    }
};