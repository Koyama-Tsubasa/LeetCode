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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // [Optimal Solution]
        // use 2 pointers, first iterate n and this means the difference
        
        // [My solution]
        // store some parameters
        int sz = 1;
        ListNode* curr = head;
        
        // preprocess (calculate the total size)
        while (curr->next != NULL) {
            
            curr = curr->next;
            sz++;
            
        }
        
        // edge case
        if (sz == 1) return NULL;
        else if (sz == n) return head->next;
        
        // start compute
        curr = head;
        for (int i=0; i<sz-n-1; i++) curr = curr->next;
        curr->next = curr->next->next;
        
        return head;
        
    }
};
