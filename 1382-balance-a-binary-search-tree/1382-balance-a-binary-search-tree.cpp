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
    void solve(TreeNode* root, vector<int>& arr) {
        if (root == NULL) {
            return;
        }
        solve(root->left, arr);
        arr.push_back(root->val);
        solve(root->right, arr);
    }
    TreeNode* build(vector<int>& arr, int low, int high) {

        if (low > high) {
            return NULL;
        }
        int mid = low + (high - low) / 2;
        TreeNode* root = new TreeNode(arr[mid]);

        root->left = build(arr, low, mid - 1);
        root->right = build(arr, mid + 1, high);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        solve(root, arr);
        int n = arr.size();
        return build(arr, 0, n - 1);
    }
};