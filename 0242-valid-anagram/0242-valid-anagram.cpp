class Solution {
public:
    bool isAnagram(string s, string t) {
        
        //base case
        if(s.size()!=t.size()) return false;

        unordered_map<char,int>mp;

        for(char ch:s){
            mp[ch]++;
            //cnt badha rhe
        }
        for(char ch:t){
            mp[ch]--;
            //freq remoe
        }
        for(auto it:mp){
            if(it.second!=0)
            return false;

        }
        return true;
    }
};