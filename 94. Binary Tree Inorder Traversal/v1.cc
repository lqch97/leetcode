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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return vector<int>();
        stack<pair<bool, TreeNode*>> s;
        vector<int> res;
        
        s.push(make_pair(false, root));
        while(!s.empty()) {
            auto x = s.top(); s.pop();
            auto flag = x.first;
            auto node = x.second;
            
            if(!flag) {
                s.push(make_pair(true, node));
                if(node->left) s.push(make_pair(false, node->left));
            }
            else {
                res.push_back(node->val);
                if(node->right) s.push(make_pair(false, node->righ));
            }
        }
        
        return res;
    }
};
