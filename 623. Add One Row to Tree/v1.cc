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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            return new TreeNode(val, root, nullptr);   
        }
        
        util(root, val, depth - 1);
        return root;
    }
    
    void util(TreeNode* root, int val, int depth) {
        if(!root) return;
        
        if(depth > 1) {
            util(root->left, val, depth - 1);
            util(root->right, val, depth - 1);
            return;
        }
        
        auto left = new TreeNode(val, root->left, nullptr), 
             right = new TreeNode(val, nullptr, root->right);
        
        root->left = left;
        root->right = right;
    }
}; 
