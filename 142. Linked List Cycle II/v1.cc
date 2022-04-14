/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// two pass solution. time: O(n), space: O(n)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !checkCycle(head)) return nullptr;
        unordered_set<ListNode*> s;
        while(s.find(head) == s.end()) {
            s.insert(head);
            head = head->next;
        }
        return head;
    }
    
    bool checkCycle(ListNode *head) {
        ListNode *i = head, *j = head;
        while(j->next && j->next->next) {
            if(j->next == i || j->next->next == i) return true;
            j = j->next->next;
            i = i->next;
        }
        return false;
    }
};
