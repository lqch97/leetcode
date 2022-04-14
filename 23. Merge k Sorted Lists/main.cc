/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ret_head = new ListNode();
        ListNode* current = ret_head;
        
        auto comp = [&](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        
        // preprocess
        for(auto head: lists) {
            if(head) pq.push(head);
        }
        
        // main algo
        while(pq.size() > 0) {
            auto temp = pq.top(); pq.pop();
            current->next = temp;
            current = current->next;
            
            if(temp->next) pq.push(temp->next);
        }
        
        // post-process
        current->next = nullptr
            // need to free first node in ret_head
        
        return ret_head -> next;
    }
};
