# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """

        # parameters
        newHead = ListNode(0, head)
        dFirst, dLast = newHead, None
        None_check = None

        # start computing
        if ((head == None) or (head.next == None)):
            return head
        else:
            dLast = dFirst.next.next
        while (dLast):
            None_check = False
            if (dFirst.next.val == dLast.val):
                while (dFirst.next.val == dLast.val):
                    dLast = dLast.next
                    if not dLast:
                        None_check = True
                        break
                dFirst.next = dLast
            else:
                dFirst = dFirst.next
            if not None_check:
                dLast = dLast.next

        return newHead.next
