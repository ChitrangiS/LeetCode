class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int, unordered_set<int>> mp;

        for (int stone : stones) {
            mp[stone];
        }
        // first 0 jump
        mp[0].insert(0);
        for (int i = 0; i < n; i++) {
            int pos = stones[i];
            // iske liye jitne possible try
            for (int jump : mp[pos]) {

                for (int nj = jump - 1; nj <= jump + 1; nj++) {
                    if (nj <= 0) {
                        continue;
                    }
                    // next pos calc
                    int nextpos = pos + nj;
                    // agar last h toh true
                    if (nextpos == stones[n - 1]) {
                        return true;
                    }
                    // check stone h ki nhi
                    if (mp.count(nextpos)) {
                        mp[nextpos].insert(nj);
                    }
                }
            }
        }
        return false;
    }
};