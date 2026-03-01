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
    bool isTrue(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr)
            return true;
        if (left == NULL || right == NULL)
            return false;
            return (left->val == right->val) &&
               isTrue(left->left, right->right) &&
               isTrue(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return (isTrue(root->left, root->right));
    }
};