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
        if(!root) return true;
        return get<2>(util(root));
    }
    
    tuple<int, int, bool> util(TreeNode* root) {
        if(!root->left && !root->right) return { root->val, root->val, true };
        
        if(!root->left) {
            auto right = util(root->right);
            return { root->val, get<1>(right), get<2>(right) && root->val < get<0>(right) };
        }
        
        if(!root->right) {
            auto left = util(root->left);
            return { get<0>(left), root->val, get<2>(left) && root->val > get<1>(left) };
        }
        
        auto left = uil(root->left);
        auto right = util(root->right);
        return {
            get<0>(left),
            get<1>(right),
            get<2>(left) && get<2>(right) && root->val < get<0>(right) && root->val > get<1>(left)
        };
    }
};
