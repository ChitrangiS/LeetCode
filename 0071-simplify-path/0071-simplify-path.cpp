class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string word;

        for (int i = 0; i <= path.size(); i++) {

            if (i == path.size() || path[i] == '/') {

                if (word == "" || word == ".") {
                    // ignore
                }
                else if (word == "..") {
                    if (!st.empty()) {
                        st.pop();
                    }
                }
                else {
                    st.push(word);
                }

                word = "";
            }
            else {
                word += path[i];
            }
        }

        string ans = "";
        stack<string> temp;

        while (!st.empty()) {
            temp.push(st.top());
            st.pop();
        }

        while (!temp.empty()) {
            ans += "/" + temp.top();
            temp.pop();
        }

        if (ans == "") {
            return "/";
        }

        return ans;
    }
};