# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        
        
        # count the length of linked list
        def CountNodes(node):
            count = 1
            while (node.next):
                count += 1
                node = node.next
            return count
        
        # parameters
        A_num, B_num = CountNodes(headA), CountNodes(headB)
        a, b = headA, headB
        
        # preprocess for matching the list length
        for i in range(A_num-B_num):
            a = a.next
        for i in range(B_num-A_num):
            b = b.next
        
        # start checking
        while (a != b):
            a = a.next
            b = b.next
        
        return a
