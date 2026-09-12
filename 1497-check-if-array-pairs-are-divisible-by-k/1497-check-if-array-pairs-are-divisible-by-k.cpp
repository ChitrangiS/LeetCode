class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k, 0);

        for(int x : arr) {
            int rem = ((x % k) + k) % k;
            freq[rem]++;
        }

        if(freq[0] % 2 != 0) return false;

        for(int rem = 1; rem < k; rem++) {
            int needed = k - rem;

            if(rem == needed) {
                if(freq[rem] % 2 != 0) return false;
            }
            else {
                if(freq[rem] != freq[needed]) return false;
            }
        }

        return true;
    }
};