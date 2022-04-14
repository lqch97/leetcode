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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return vector<vector<int>>(); //edge case
        
        vector<vector<int>> res;
        queue<pair<TreeNode*, int>> q; // (node, level)
        
        vector<int> vec_curr_level;
        int curr_level = 0;
        q.push(make_pair(root, 0));
        
        while(!q.empty()) {
            auto temp = q.front(); q.pop();
            auto node = temp.first;
            auto level = temp.second;
            
            if(level != curr_level) {
                res.push_back(vec_curr_level);
                vec_curr_level.clear();
                currlevel = level;
            }
            
            vec_curr_level.push_back(node->val);
            if(node->left) q.push(make_pair(node->left, level+1));
            if(node->right) q.push(make_pair(node->right, level+1));
        }
        
        res.push_back(vec_curr_level);
        
        return res;
    }
};_
