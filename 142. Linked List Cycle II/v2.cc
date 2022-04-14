/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// time: O(n), space: O(1) solution
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* meet_pos;
        if(!(meet_pos = checkCycle(head))) return nullptr;
        while(head != meet_pos) {
            head = head->next;
            meet_pos = meet_pos->next;
        }
        return head;
    }
    
    ListNode* checkCycle(ListNode *head) {
        ListNode *i = head, *j = head;
        while(j && j->next) {
            i = i->next;
            j = j->next->next;
            if(i == j) return i;
        }
        return nullptr;
    }
};
