#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) return result;
        stack<TreeNode *> s;
        s.push(root);
        while(!s.empty()) {
            TreeNode *node = s.top();
            result.push_back(node->val);
            s.pop();
            if(node->right != nullptr) s.push(node->right);
            if(node->left != nullptr) s.push(node->left);
        }

        return result;
    }
};