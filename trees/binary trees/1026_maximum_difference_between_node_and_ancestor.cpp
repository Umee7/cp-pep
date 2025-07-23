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
    int MAX_DIFF = INT_MIN;
    void findMax(TreeNode *root, int currentMax, int currentMin) {
        if(root == nullptr) return;
        currentMax = max(currentMax, root->val);
        currentMin = min(currentMin, root->val);
        int diff = abs(currentMax - currentMin);
        if(diff > MAX_DIFF) MAX_DIFF = diff;

        findMax(root->left, currentMax, currentMin);
        findMax(root->right, currentMax, currentMin);

    }
    int maxAncestorDiff(TreeNode* root) {
        findMax(root, root->val, root->val);
        return MAX_DIFF;
    }
};