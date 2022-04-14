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
    void flatten(TreeNode* root) {
        util(root);
    }
    
    TreeNode* util(TreeNode* root) { // return value: the right most tree node
        if(!root) return nullptr;
        if(!root->left && !root->right) return root;
        if(!root->left) return util(root->right);
        
        if(!root->right) {
            auto last_of_left = util(root->left);
            root->right = root->left;
            root->left = nullptr;
            return last_of_left;
        }
        
        auto left = root->left, right = root->right;
        auto last_of_left = util(left);
        auto last_of_right = util(right);
       
        root->left = nullptr;
        root->right = left;
        last_of_left->right = right;
        
        return last_of_right;
    }
}; 
