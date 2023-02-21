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
    ListNode* rotateRight(ListNode* head, int k) {
        
        // parameter
        int listLength = 0;
        ListNode *cur, *r_point;

        // start computing
        
        // calculate list length
        cur = head;
        while (cur != NULL) {

            listLength++;
            cur = cur->next;

        }

        // verify if it can rotate
        if (listLength <= 1) return head;
        else {

            k %= listLength;

            // find the new end node
            cur = head;
            for (int i=1; i<(listLength-k); i++) cur = cur->next;
            r_point = cur;
            
            // find the current end node
            while (cur->next != NULL) cur = cur->next;
            
            // start rotate
            cur->next = head;
            head = r_point->next;
            r_point->next = NULL;

        }

        return head;

    }
};
