# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        
        # parameters
        fast, slow = head, head
        
        # start compute, using Floyd's Cycle-Finding Algorithm
        while (fast!=None and fast.next!=None):
            fast = fast.next.next
            slow = slow.next
            if (fast == slow):
                return True
        
        return False
        
