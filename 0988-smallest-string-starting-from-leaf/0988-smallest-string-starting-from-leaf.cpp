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
    vector<string> arr;
    void solve(TreeNode* root, string path) {

        if (root == NULL) {
            return;
        }
        char ch = 'a' + root->val;
        path += ch;

        if (root->left == NULL && root->right == NULL) {
            reverse(path.begin(), path.end());
            arr.push_back(path);
            return;
        }
        solve(root->left, path);
        solve(root->right, path);
    }
    string smallestFromLeaf(TreeNode* root) {
        solve(root, "");
        sort(arr.begin(), arr.end());
        return arr[0];
    }
};