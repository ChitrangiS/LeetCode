class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int n = sentences.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {

            stringstream ss(sentences[i]);

            string word;
            int count = 0;

            while (ss >> word) {
                count++;
            }
            ans = max(count, ans);
        }
        return ans;
    }
};