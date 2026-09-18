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
    int maxLevelSum(TreeNode* root) {

        if (root == NULL) {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);

        int ans = 1;
        int level = 1;
        int maxsum = INT_MIN;

        while (!q.empty()) {
            int n = q.size();

            int levelsum = 0;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                levelsum += node->val;
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
            if (levelsum > maxsum) {
                maxsum = levelsum;
                ans = level;
            }
            level++;
        }
        return ans;
    }
};