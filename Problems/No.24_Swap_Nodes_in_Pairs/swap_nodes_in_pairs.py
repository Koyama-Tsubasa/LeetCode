# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        
        # start compute
        if not head:        # if the list size is 0
            return head
        elif not head.next: # if the list size is 1
            return head
        else:
            
            # change the head pointer and set the initial left, right
            left = head
            right = head.next
            head = head.next
            
            # start iterating
            while (True):
                
                # set the check and first solve the right->next pointer
                check = right.next
                right.next = left
                
                # case for remaining nodes are 0, 1, and >2
                if not check:
                    left.next = None
                    break
                elif not check.next:
                    left.next = check
                    break
                else:
                    left.next = check.next
                    left = check
                    right = check.next
            
        return head
        
