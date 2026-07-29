class Solution {
public:
    void reverseString(vector<char>& s) {

        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};
//bf:take temp ans then  r->l ans+=s[i] o(n),o(n)
//use stack
//optimal:two ptr(l<r) swap o(n),o(1)