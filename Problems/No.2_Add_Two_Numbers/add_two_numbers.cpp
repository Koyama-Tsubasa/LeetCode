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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // create the parameter to store partial sum and carry
        int partial_sum;
        int carry = 0;
        
        // create the list of answer
        ListNode* l_ans = new ListNode(0);
        ListNode* ans = l_ans;
        
        
        // start compute
        while(l1 or l2 or carry) {
            
            // calculate partial sum and carry
            partial_sum = carry;
            if (l1) {
                
                partial_sum += l1->val;
                l1 = l1->next;
                
            }
            if (l2) {
                
                partial_sum += l2->val;
                l2 = l2->next;
                
            }
            carry = partial_sum/10;
            partial_sum = partial_sum%10;
            
            // create new node with partial_sum/10
            ListNode* new_node = new ListNode(partial_sum);
            l_ans->next = new_node;
            l_ans = l_ans->next;
            
        }
        
        return ans->next;
        
    }
};
