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
        if(!root) return;
        
        vector<TreeNode*> pre_res;
        preorder(pre_res, root);
        int n = pre_res.size();
        
        for(int i = 0; i < n - 1; ++i) {
            pre_res[i]->left = nullptr;
            pre_res[i]->right = pre_res[i+1];
        }
        pre_res[n-1]->left = nullptr;
        pre_res[n-1]->right = nullptr;
    }
    
    void preorder(vector<TreeNode*> &res, TreeNode* root) {
        if(!root) return;
        res.push_back(root);
        preorder(res, root->left);
        preorder(res, root->right);
    }
};
