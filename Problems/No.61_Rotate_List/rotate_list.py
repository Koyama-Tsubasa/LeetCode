# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """

        # parameters
        listLength = 0
        cur, r_point = None, None

        # start computing
        # calculate list length
        cur = head
        while cur:
            listLength += 1
            cur = cur.next
        
        # verify if it can rotate
        if (listLength <= 1):
            return head
        else:

            k %= listLength

            # find the new end node
            cur = head
            for i in range(1, listLength-k):
                cur = cur.next
            r_point = cur
        
            # find the current end node
            while cur.next:
                cur = cur.next
            
            # start rotate
            cur.next = head
            head = r_point.next
            r_point.next = None
        
        return head
