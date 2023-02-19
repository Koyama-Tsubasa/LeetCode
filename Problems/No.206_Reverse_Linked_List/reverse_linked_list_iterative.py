# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """

        # parameters
        reversed_head, next_head = None, None

        # start computing
        while head:
            next_head = head.next
            head.next = reversed_head
            reversed_head = head
            head = next_head
        
        return reversed_head
