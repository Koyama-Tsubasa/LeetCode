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
    ListNode* removeElements(ListNode* head, int val) {
        
        // parameter
        ListNode* curr = head;
        ListNode* prev;

        // check the first value
        while (head != NULL) {

            if (head->val == val) {

                curr = curr->next;
                head = head->next;

            }
            else break;

        }

        // check the internal value
        prev = curr;
        if (curr != NULL) curr = curr->next;
        while (curr != NULL) {
            
            if (curr->val == val) prev->next = curr->next;
            else prev = prev->next;
            curr = curr->next;

        }

        return head;

    }
};
