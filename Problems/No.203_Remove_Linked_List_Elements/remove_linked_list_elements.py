# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """

        # parameters
        curr, prev = None, None

        # check the first value
        while (head != None):
            if (head.val == val):
                head = head.next
            else:
                break

        # check the internal value
        curr, prev = head, head
        if (curr != None):
            curr = curr.next
        while (curr != None):
            if (curr.val == val):
                prev.next = curr.next
            else:
                prev = prev.next
            curr = curr.next
        
        return head
