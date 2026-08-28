/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> mp;

    TreeNode* solve(vector<int>& inorder, int inStart, int inEnd,
                    vector<int>& postorder, int postStart, int postEnd) {
        
        if (inStart > inEnd || postStart > postEnd) {
            return NULL;
        }

        int rootValue = postorder[postEnd];
        TreeNode* root = new TreeNode(rootValue);

        int rootIndex = mp[rootValue];
        int leftSize = rootIndex - inStart;

        root->left = solve(inorder, inStart, rootIndex - 1,
                           postorder, postStart, postStart + leftSize - 1);

        root->right = solve(inorder, rootIndex + 1, inEnd,
                            postorder, postStart + leftSize, postEnd - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return solve(inorder, 0, inorder.size() - 1,
                     postorder, 0, postorder.size() - 1);
    }
};