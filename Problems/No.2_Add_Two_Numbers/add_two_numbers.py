# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        
        carry = 0                 # parameter to store carry
        ans = l_ans = ListNode()  # create the list of answer
        
        # start compute
        while (l1 or l2 or carry):
            
            # calculate partial sum and carry
            partial_sum = carry
            if l1:
                partial_sum += l1.val
                l1 = l1.next
            if l2:
                partial_sum += l2.val
                l2 = l2.next
            carry = partial_sum/10
            partial_sum %= 10
            
            # create new node with partial_sum/10
            l_ans.next = ListNode(partial_sum)
            l_ans = l_ans.next
        
        return ans.next
