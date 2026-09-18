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
    unordered_map<int, int> mp;
    void solve(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        mp[root->val]++;
        solve(root->left);
        solve(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        solve(root);
        if (root == NULL) {
            return ans;
        }
        int maxi = 0;
        for (auto it : mp) {
            maxi = max(maxi, it.second);
        }
        for (auto it : mp) {
            if (it.second == maxi) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};