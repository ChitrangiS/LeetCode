class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {

        unordered_map<int, int> mp;
        int cnt = 0;

        for (int x : time) {
            int rem = x % 60;

            int need = (60 - rem) % 60;
            if (mp.find(need) != mp.end()) {
                cnt += mp[need];
            }
            mp[rem]++;
        }
        return cnt;
    }
};