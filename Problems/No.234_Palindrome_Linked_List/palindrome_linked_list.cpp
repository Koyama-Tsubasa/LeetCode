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
    bool isPalindrome(ListNode* head) {
        
        // parameters
        ListNode *front = head, *back = head;
        ListNode *reverse_back;

        // start computing (use Floyd's algorithm)
        
        // find the midium value
        while (back && back->next) {

            front = front->next;
            back = back->next->next;

        }

        // reversal step
        reverse_back = front->next;
        front->next = NULL;
        while (reverse_back) {

            back = reverse_back->next;
            reverse_back->next = front;
            front = reverse_back;
            reverse_back = back;

        }

        // comparison step
        back = front;
        front = head;
        while (back) {

            if (front->val == back->val) {

                front = front->next;
                back = back->next;

            }
            else return false;

        }

        return true;

    }
};
