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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        unsigned long long ans = 0;
        while (!q.empty()) {
            int n = q.size();
            unsigned long long start = q.front().second;
            unsigned long long first = 0;
            unsigned long long last = 0;

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front().first;
                unsigned long long index = q.front().second - start;
                q.pop();

                if (i == 0) {
                    first = index;
                }
                if (i == n - 1) {
                    last = index;
                }
                if (node->left != NULL) {
                    q.push({node->left, 2 * index + 1});
                }
                if (node->right != NULL) {
                    q.push({node->right, 2 * index + 2});
                }
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};