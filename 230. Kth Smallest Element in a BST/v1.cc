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
    int kthSmallest(TreeNode* root, int k) {
        int cnt = k;
        int res = -1;
        util(root, cnt, res);
        return res;
    }
    
    void util(TreeNode* root, int& cnt, int& res) {
        if(!root) return;
        util(root->left, cnt, res);
        if(!--cnt) res = root->val;
        if(cnt) util(root->right, cnt, res);
    }
};
