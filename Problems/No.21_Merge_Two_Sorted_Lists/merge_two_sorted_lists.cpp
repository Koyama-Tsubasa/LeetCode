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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // check if the initial lists contains NULL list
        if (list1 == NULL) return list2;
        else if (list2 == NULL) return list1;
        else {
            
            
            // create the solution pointer and the current pointer in the solution
            ListNode* solution;
            ListNode* cur;
            
            // add the first solution
            if (list1->val < list2->val) {
                
                solution = list1;
                list1 = list1->next;
                
            }
            else {
                
                solution = list2;
                list2 = list2->next;
                
            }
            
            // check which value is smaller and add to the next of the current solution iteratively
            cur = solution;
            while (list1 and list2) {
                
                if (list1->val < list2->val) {
                    
                    cur->next = list1;
                    list1 = list1->next;
                    
                    
                }
                else {
                    
                    cur->next = list2;
                    list2 = list2->next;
                    
                }
                cur = cur->next;
                
            }
            
            // if one of the list is not all visited then add
            if (list1) cur->next = list1;
            else if (list2) cur->next = list2;
            
            return solution;
            
        }
        
    }
};
