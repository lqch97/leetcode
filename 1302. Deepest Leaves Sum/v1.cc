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
    int deepestLeavesSum(TreeNode* root) {
        int max_depth = -1;
        int sum;
        util(root, 0, max_depth, sum);
        return sum;
    }
    
    void util(TreeNode* root, int depth, int& max_depth, int& sum) {
        if(!root) return;
        if(root->left) util(root->left, depth + 1, max_depth, sum);
        if(root->right) util(root->right, depth + 1, max_depth, sum);
        if(depth == max_depth) sum += root->val;
        if(depth > max_depth) {
            max_depth = depth;
            sum = root->val;
        }
    }
};
