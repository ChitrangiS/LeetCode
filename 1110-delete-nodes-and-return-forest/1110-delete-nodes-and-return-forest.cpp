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
    vector<TreeNode*> ans;
    unordered_set<int> del;

    TreeNode* solve(TreeNode* root, bool isRoot) {
        if (root == NULL) {
            return NULL;
        }

        bool deleted = del.count(root->val);
        if (isRoot && !deleted) {
            ans.push_back(root);
        }
        root->left = solve(root->left, deleted);
        root->right = solve(root->right, deleted);

        if (deleted)
            return NULL;

        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {

        for (int x : to_delete) {
            del.insert(x);
        }
        solve(root, true);

        return ans;
    }
};