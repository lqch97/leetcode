/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        vector<Node*> prev;
        util(root, 0, prev);
        return root;
    }
    
    void util(Node* root, int depth, vector<Node*>& prev) {
        if(!root) return;
        
        if(prev.size() <= depth) {
            prev.push_back(root);
            root->next = nullptr;
        } else {
            root->next = prev[depth];
            prev[depth] = root;
        }
        
        util(root->right, depth + 1, prev);
        util(root->left, depth + 1, prev);
    }
};
