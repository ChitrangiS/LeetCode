class Solution {
public:
    int secondHighest(string s) {
        set<int> st;

        for(char ch : s) {
            if(isdigit(ch)) {
                st.insert(ch - '0');
            }
        }

        if(st.size() < 2)
            return -1;

        auto it = st.rbegin(); 
        it++;                 

        return *it;
    }
};