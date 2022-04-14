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
        return doubleDFS(root, makeInverse(root));
    }
    
    TreeNode* makeInverse(TreeNode* root) {
        if(!root) return nullptr;
        
        auto new_root = new TreeNode(root->val);
        new_root->left = makeInverse(root->right);
        new_root->right = makeInverse(root->left);
        
        return new_root;
    }
    
    bool doubleDFS(TreeNode* x, TreeNode* y) {
        if(!x && !y) return true;
        if(!x || !y) return false; // else if
        
        if(x->val != y->val) return false;
        if(!doubleDFS(x->left, y->left)) return false;
        return doubleFS(x->right, y->right);
    }
};
