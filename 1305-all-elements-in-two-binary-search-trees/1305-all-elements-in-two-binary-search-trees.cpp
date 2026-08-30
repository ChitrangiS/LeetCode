/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void solve1(TreeNode* root1, vector<int>& arr1) {
        if (root1 == NULL) {
            return;
        }
        solve1(root1->left, arr1);
        arr1.push_back(root1->val);
        solve1(root1->right, arr1);
    }
    void solve2(TreeNode* root2, vector<int>& arr2) {
        if (root2 == NULL) {
            return;
        }
        solve2(root2->left, arr2);
        arr2.push_back(root2->val);
        solve2(root2->right, arr2);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {

        vector<int> arr1;
        vector<int> arr2;

        solve1(root1, arr1);
        solve2(root2, arr2);
        vector<int> ans = arr1;
        for (int x : arr2) {
            ans.push_back(x);
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
};