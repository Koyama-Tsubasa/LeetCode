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
    
    // count the number of nodes
    int CountNodes(ListNode *node) {
        
        int count = 1;
        while (node->next) {
            
            count++;
            node = node->next;
            
        }
        
        return count;
        
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     
        // parameters
        int A_num = CountNodes(headA);
        int B_num = CountNodes(headB);
        ListNode *a = headA, *b = headB;
        
        // preprocess to match the list length
        for (int i=0; i<A_num-B_num; i++) a = a->next;
        for (int i=0; i<B_num-A_num; i++) b = b->next;
        
        // start checking
        while (a != b) {
            
            a = a->next;
            b = b->next;
            
        }
        
        return a;
        
    }
};
