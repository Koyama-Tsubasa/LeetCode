# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """

        # parameters
        less, greater = ListNode(), ListNode()
        LHead, GHead = less, greater

        # start computing
        while head:
            if (head.val < x):
                less.next = head
                less = less.next
            else:
                greater.next = head
                greater = greater.next
            head = head.next
        less.next = GHead.next
        greater.next = None
    
        return LHead.next
