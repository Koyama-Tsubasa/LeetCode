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
        int partial_sum = 0;
        int carry = 0;
      
        // create the list of answer
        ListNode* l_ans = new ListNode(0); 
        ListNode* ans = l_ans;
        
        // add two numbers until one becomes null
        while(l1 and l2) {
            
            // calculate partial sum and carry
            partial_sum = l1->val + l2->val + carry;
            carry = partial_sum/10;
            partial_sum = partial_sum%10;
            
            // create new node with partial_sum/10
            ListNode* new_node = new ListNode(partial_sum);
            l_ans->next = new_node;
            
            l1 = l1->next;
            l2 = l2->next;
            l_ans = l_ans->next;
            
        }
        
        // check if l1 and l2 are all visited
        while(l1 or l2) {
            
            // calculate partial sum and carry
            if (l1) {
                
                partial_sum = l1->val + carry;
                l1 = l1->next;
                
            }
            else {
                
                partial_sum = l2->val + carry;
                l2 = l2->next;
                
            }
            carry = partial_sum/10;
            partial_sum = partial_sum%10;
            
            // create new node with partial_sum/10
            ListNode* new_node = new ListNode(partial_sum);
            l_ans->next = new_node;
            l_ans = l_ans->next;
            
        }
        
        // check if the last carry is 1
        if (carry) {
            
            ListNode* new_node = new ListNode(carry);
            l_ans->next = new_node;
            
        }
        
        return ans->next;
        
    }
};
