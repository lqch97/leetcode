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
    int goodNodes(TreeNode* root) {
        return root ? util(root, root->val) : 0;
    }
    
    int util(TreeNode* root, int max_val) {
        auto val = root->val;
        auto res = (max_val > val) ? 0 : 1;
        max_val = max(max_val, val);
        if(root->left) res += util(root->left, max_val);
        if(root->right) res += util(root->right, max_val);
        return res;
    }
};
