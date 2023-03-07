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
    ListNode* partition(ListNode* head, int x) {
        
        // parameters
        ListNode *less = new ListNode();
        ListNode *greater = new ListNode();
        ListNode *LHead = less, *GHead = greater;

        // start computing
        while (head) {

            if (head->val < x) {

                less->next = head;
                less = less->next;

            }
            else {

                greater->next = head;
                greater = greater->next;

            }
            head = head->next;

        }
        less->next = GHead->next;
        greater->next = NULL;

        return LHead->next;

    }
};
