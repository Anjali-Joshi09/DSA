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
    int diameter(TreeNode* root,int &maxi)
    {
        if(root==nullptr)
        return 0;
        int lh=diameter(root->left,maxi);
        int rh=diameter(root->right,maxi);
        maxi=max((lh+rh),maxi);
        return 1+ max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        int ans= diameter(root,maxi);
        return maxi;
    }
};