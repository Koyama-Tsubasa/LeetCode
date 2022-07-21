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
    
    // reverse K nodes from first to last
    ListNode* reverseKnodes(ListNode* first, ListNode* last) {
        
        // parameters
        ListNode *temp;
        ListNode *connect = last->next;;
        
        // startcompute
        while (first != last) {
            
            temp = first->next;
            first->next = connect;
            connect = first;
            first = temp;
            
        }
        first->next = connect;
        
        return last;
        
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        // parameters
        ListNode *first, *last, *previous;
        bool starting_flag = 1;
        
        // start compute
        if (head->next==NULL or k==1) return head;
        else {
            
            first = head;
            last = head;
            
            // iterate until the last collides into NULL
            while (last) {
                
                // check if the remaining nodes have more than k
                for (int i=1; i<k; i++) {
                    
                    last = last->next;
                    if (not last) return head;
                    
                }
                
                // check if it is the first reversion
                if (starting_flag) {
                    
                    head = reverseKnodes(first, last);
                    starting_flag = 0;
                    
                }
                else previous->next = reverseKnodes(first, last);
                
                previous = first;
                last = first->next;
                first = first->next;
                
            }
            
            return head;
            
        }
        
    }
};
