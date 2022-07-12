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
    ListNode* deleteDuplicates(ListNode* head) {
        
        // parameters
        int current_value;
        ListNode* current_node;
        ListNode* check;
        
        // start compute
        if (head == NULL) return head;
        else {
            
            current_node = head;
            check = head->next;
            current_value = current_node->val;
            
            // start checking
            while (check != NULL) {
                
                if (check->val != current_value) {
                    
                    current_node->next = check;
                    current_node = check;
                    current_value = current_node->val;
                    
                }
                check = check->next;
                
            }
            
            current_node->next = NULL;
            
        }
        
        return head;
        
    }
};
