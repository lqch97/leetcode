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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return doubleDFS(root->left, root->right);
    }
    
    bool doubleDFS(TreeNode* x, TreeNode* y) {
        if(!x && !y) return true;
        if(!x || !y) return false; // else if
        
        if(x->val != y->val) return false;
        if(!doubleDFS(x->left, y->right)) return false;
        return doubleDFS(x->right, y->left);
    }
};
