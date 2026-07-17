class Solution {
public:
    int clumsy(int n) {
        stack<int> st;
        st.push(n);
        int op = 0; // 0 for * 1 for / ..
        for (int i = n-1; i >= 1; i--) {

            if (op == 0) {
                int x = st.top();
                st.pop();
                st.push(x * i);
            } else if (op == 1) {
                int x = st.top();
                st.pop();
                st.push(x / i);
            } else if (op == 2) {
                int x = st.top();
                st.pop();
                st.push(x + i);
            } else {
                st.push( - i);
            }
            op = (op + 1) % 4;
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};