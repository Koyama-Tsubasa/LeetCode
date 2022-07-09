# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        
        # [Optimal Solution]
        # use 2 pointers, first iterate n and this means the difference
        
        # [My solution]
        # store some parameters
        curr = head
        sz = 1
        
        # preprocess (calculate the total size)
        while (curr.next != None):
            curr = curr.next
            sz += 1
        
        # edge case
        if (sz == 1):
            return None
        elif (sz == n):
            return head.next
        
        # start compute
        curr = head
        for i in range(sz-n-1):
            curr = curr.next
        curr.next = curr.next.next
        
        return head
