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
    bool isleaf(TreeNode* root) {
        if (root == NULL) {
            return false;
        }
        return root->left == NULL && root->right == NULL;
    }
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;
        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (isleaf(node)) {
                    return depth; // bfs mai jo root pehle aya that is min
                }
                if (node->left != NULL) {
                    q.push(node->left);
                }

                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
            depth++;
        }
        return depth;
    }
};