# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseBetween(self, head, left, right):
        """
        :type head: ListNode
        :type left: int
        :type right: int
        :rtype: ListNode
        """

        # parameters
        curr, prev = head, None
        before_left, reverse_end, reverse_next = None, None, None

        # start computing
        if (left == right):
            return head
        
        # find the left node
        for i in range(1, left):
            prev = curr
            curr = curr.next
        
        # start reversing
        before_left = prev
        reverse_end = curr
        reverse_next = curr.next
        for i in range(right-left+1):
            curr.next = prev
            prev = curr
            curr = reverse_next
            if reverse_next:
                reverse_next = reverse_next.next
        
        # reconnection
        if before_left:
            before_left.next = prev
        else:
            head = prev
        reverse_end.next = curr
    
        return head
