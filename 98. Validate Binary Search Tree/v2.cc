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
    bool isValidBST(TreeNode* root) {
        int prev;
        bool first = true;
        return inorder(root, prev, first);
    }
    
    bool inorder(TreeNode* root, int& prev, bool& first) {
        if(!root) return true;
        if(!inorder(root->left, prev, first)) return false;
        
        if(!first && !(prev < root->val)) return false;
        prev = root->val;
        if(first) first = false;
        
        if(!inorder(root->right, prev, first)) return false;
        return true;
    }
};
