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
    unordered_map<int,int>mp;
    TreeNode*solve(vector<int>& preorder,int prestart,int preend ,vector<int>& inorder,int instart,int inend){
        //base case
        if(prestart>preend || instart>inend){
            return NULL;
        }

        int rootnode=preorder[prestart];
        TreeNode*root=new TreeNode(rootnode);
        int rootidx=mp[rootnode];
        int leftsize=rootidx-instart;

        //make left subtree
        root->left=solve(preorder,prestart+1,prestart+leftsize,inorder,instart,rootidx-1);root->right=solve(preorder,prestart+leftsize+1,preend,inorder,rootidx+1,inend);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //store inorder
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return solve(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};