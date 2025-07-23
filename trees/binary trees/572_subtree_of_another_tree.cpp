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
    bool sameTree(TreeNode *root, TreeNode *subRoot) {
        if (!root && !subRoot) return true;  
        if (!root || !subRoot) return false;     
        if (root->val != subRoot->val) return false; 
        return sameTree(root->left, subRoot->left) && sameTree(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == nullptr) return true;
        if(root == nullptr ) return false;
        if(root->val == subRoot->val) {
            if (sameTree(root, subRoot)) {
                return true;
            }
        }


        bool left =  isSubtree(root->left, subRoot);


        bool right = isSubtree(root->right, subRoot);

        return left || right;

    }
};