/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        // parameters
        ListNode *fast = head;
        ListNode *slow = head;
        
        // start compute, using Floyd's Cycle-Finding Algorithm
        while (fast!=NULL and fast->next!=NULL) {
            
            fast = fast->next->next;
            slow = slow->next;   
            
            if (fast == slow) return true;
            
        }
        
        return false;
        
    }
};
