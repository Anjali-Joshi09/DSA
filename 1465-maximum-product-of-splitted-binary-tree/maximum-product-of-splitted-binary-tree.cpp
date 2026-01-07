class Solution {
public:
    long long totalSum = 0;
    long long bestProduct = 0;
    const int MOD = 1e9 + 7;

    long long treeSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + treeSum(root->left) + treeSum(root->right);
    }

    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long subTreeSum = root->val + left + right;

        bestProduct = max(bestProduct, subTreeSum * (totalSum - subTreeSum));

        return subTreeSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = treeSum(root);
        dfs(root);
        return bestProduct % MOD;
    }
};
