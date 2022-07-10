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
    ListNode* swapPairs(ListNode* head) {
        
        // left -> right -> check
        ListNode* left;
        ListNode* right;
        ListNode* check;
        
        // start compute
        if (not head) return head;              // if the list size is 0
        else if (not head->next) return head;   // if the list size is 1
        else {
            
            // change the head pointer and set the initial left, right
            left = head;
            right = head->next;
            head = head->next;
            
            // start iterating
            while (true) {
                
                // set the check and first solve the right->next pointer
                check = right->next;
                right->next = left;
                
                // case for remaining nodes are 0, 1, and >2
                if (not check) {
                    
                    left->next = NULL;
                    break;
                    
                }
                else if (not check->next) {
                    
                    left->next = check;
                    break;
                    
                }
                else {
                    
                    left->next = check->next;
                    left = check;
                    right = check->next;
                    
                }
                
            }
            
        }
        
        return head;
        
    }
};
