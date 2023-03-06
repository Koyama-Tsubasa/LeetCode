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
        ListNode *newHead = new ListNode(0, head);
        ListNode *dFirst = newHead, *dLast;
        bool NULL_check;

        // start computing
        if ((head == NULL) || (head->next == NULL)) return head;
        else dLast = dFirst->next->next;
        while (dLast != NULL) {

            NULL_check = false;
            if (dFirst->next->val == dLast->val) {

                while (dFirst->next->val == dLast->val) {

                    dLast = dLast->next;
                    if (dLast == NULL) {

                        NULL_check = true;
                        break;

                    }

                }
                dFirst->next = dLast;

            }
            else dFirst = dFirst->next;

            if (!NULL_check) dLast = dLast->next;

        }

        return newHead->next;

    }
};
