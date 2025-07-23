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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();
                if (level == depth - 1) {

                    TreeNode* node1 = new TreeNode(val);
                    node1->left = front->left;
                    front->left = node1;

                    TreeNode* node2 = new TreeNode(val);
                    node2->right = front->right;
                    front->right = node2;

                } else {
                    if (front->left)
                        q.push(front->left);
                    if (front->right)
                        q.push(front->right);
                }
            }
            level++;
        }

        return root;
    }
};