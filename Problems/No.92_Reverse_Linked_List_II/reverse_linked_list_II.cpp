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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        // parameters
        ListNode *curr = head, *prev = NULL;
        ListNode *before_left, *reverse_end, *reverse_next;

        // start computing
        if (left == right) return head;

        // find the left node
        for (int i=1; i<left; i++) {

            prev = curr;
            curr = curr->next;

        }

        // start reversing
        before_left = prev;
        reverse_end = curr;
        reverse_next = curr->next;
        for (int i=0; i<(right-left+1); i++) {

            curr->next = prev;
            prev = curr;
            curr = reverse_next;
            if (reverse_next != NULL) reverse_next = reverse_next->next;

        }

        // reconnection
        if (before_left != NULL) before_left->next = prev;
        else head = prev;
        reverse_end->next = curr;

        return head;

    }
};
