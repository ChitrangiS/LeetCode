class Solution {
public:
    int clumsy(int n) {
        stack<int> st;
        st.push(n);
        int p = 0;
        for (int i = n - 1; i >= 1; i--) {
            if (p == 0) {
                int x = st.top();
                st.pop();
                st.push(x * i);
            } else if (p == 1) {
                int x = st.top();
                st.pop();
                st.push(x / i);
            } else if (p == 2) {
                int x = st.top();
                st.pop();
                st.push(x + i);
            } else {
                st.push(-i);
            }
            p = (p + 1) % 4;
        }
        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};