class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        int write = 0;

        while (i < n) {
            char c = chars[i];
            int j = i;

            while (j < n && chars[j] == c) {
                j++;
            }
            int count = j - i;
            // write the char
            chars[write++] = c;
            if (count > 1) {
                string num = to_string(count);

                for (char c : num) {
                    chars[write++] = c;
                }
            }
            i = j;
        }
        return write;
    }
};