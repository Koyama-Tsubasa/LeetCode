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
    ListNode* reverseList(ListNode* head) {
        
        // parameter
        ListNode *reversed_head, *next_head;
        
        // start computing
        reversed_head = NULL;
        while (head != NULL) {

            next_head = head->next;
            head->next = reversed_head;
            reversed_head = head;
            head = next_head;

        }

        return reversed_head;

    }
