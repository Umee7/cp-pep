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
    long long MAX_PRODUCT = INT_MIN;
    int subTreeSum(TreeNode* root, long long totalSum) {
        if(root == nullptr) return 0;
        long long s1 = subTreeSum(root->left, totalSum) + subTreeSum(root->right, totalSum) + root->val;
        long long s2 = totalSum - s1;
        long long product = s1 * s2;
        MAX_PRODUCT = max(product, MAX_PRODUCT);
        return s1;
    }

    long long totalSum(TreeNode* root) {
        if(root==nullptr) return 0;
        int leftSum = totalSum(root->left);
        int rightSum = totalSum(root->right);
        return leftSum + rightSum + root->val;
    }

    int maxProduct(TreeNode* root) {
        int mod = (int)1e9+7;
        long long sum = totalSum(root);
        subTreeSum(root, sum);
        return (int)(MAX_PRODUCT%mod);
    }
};